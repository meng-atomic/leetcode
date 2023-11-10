#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <atomic>
#include <mutex>

std::mutex _g_io_mtx;

void log(const std::string& content) {
  std::lock_guard<std::mutex> lck(_g_io_mtx);
  std::cout << std::this_thread::get_id() << ": " << content << std::endl;
}

template<typename T>
class CircularBuffer {
public:
  CircularBuffer(int32_t size) : _size(size){}

private:
  T* _buffer;
  std::mutex _mtx;
  int32_t _read_idx{0};
  int32_t _write_idx{1};
  const int32_t _size{8};
};

template<typename T>
class LockFreeCircularBuffer {
public:
  LockFreeCircularBuffer(int32_t size) : _size(size) {
    _buffer = new T[_size];
  }

  ~LockFreeCircularBuffer() {

  }

  void push(const T& data) {
    // every thread should try to allocate space for writing in the buffer
    // however, if the buffer is full, the thread should wait
    int32_t curr_write_idx = _write_idx.load(std::memory_order_relaxed);
    do {
      while ((curr_write_idx + 1) % _size == _read_idx.load(std::memory_order_relaxed)) {
        // log("buffer full " + std::to_string(curr_write_idx));
        // std::this_thread::sleep_for(std::chrono::microseconds(500));
        std::this_thread::yield();
      }
    } while (!_write_idx.compare_exchange_weak(curr_write_idx, (curr_write_idx + 1) % _size));

    // log("writing to   write idx " + std::to_string(curr_write_idx));
    _buffer[curr_write_idx] = data;
    // log("writing done write idx " + std::to_string(curr_write_idx));

    while (!_read_fence.compare_exchange_weak(curr_write_idx, (curr_write_idx + 1) % _size)) {
      std::this_thread::yield();
    }
    // log("update read fence to " + std::to_string(_read_fence));
  }

  T pop() {
    int32_t curr_read_idx = _read_idx.load(std::memory_order_relaxed);
    do {
      while (curr_read_idx == _read_fence.load(std::memory_order_relaxed)) {
        // std::this_thread::sleep_for(std::chrono::microseconds(500));
        // log("buffer empty " + std::to_string(curr_read_idx) + ", fence " + std::to_string(_read_fence));
      }
    } while (!_read_idx.compare_exchange_weak(curr_read_idx, (curr_read_idx + 1) % _size));
    auto data = _buffer[curr_read_idx];
    // log("pop index " + std::to_string(_read_idx) + ", fence: " + std::to_string(_read_fence) + ", data: " + std::to_string(data));
    return data;
  }

  int32_t size() {
    int32_t read_idx = _read_idx;
    int32_t fence_idx = _read_fence;
    if (fence_idx >= read_idx) {
      return fence_idx - read_idx;
    }
    return _size - (read_idx - fence_idx);
  }

private:
  T* _buffer;
  std::atomic<int32_t> _read_idx{0};
  std::atomic<int32_t> _write_idx{0};
  std::atomic<int32_t> _read_fence{0};
  const int32_t _size{8};
};

void test_push() {
  std::vector<std::thread> producers;
  producers.reserve(1);
  LockFreeCircularBuffer<int> buffer(4);
  for (int i = 0; i < 4; ++i) {
    producers.emplace_back([&](){
      int count = 2;
      while (--count) {
        buffer.push(count);
      }
    });
  }
  
  for (auto& p : producers) {
    if (p.joinable()) {
      p.join();
    }
  }
}

void test_pop() {
  LockFreeCircularBuffer<int> buffer(4);
  buffer.push(1);
  buffer.push(2);
  buffer.push(3);

  std::vector<std::thread> consumers;
  consumers.reserve(10);
  for (int i = 0; i < 4; ++i) {
    consumers.emplace_back([&](){
      int count = 2;
      while (--count) {
        buffer.pop();
      }
    });
  }
}

void test_pop1() {
  LockFreeCircularBuffer<int> buffer(4);
  buffer.push(1);
  buffer.push(2);
  buffer.push(3);
  log(std::to_string(buffer.pop()));
  log(std::to_string(buffer.pop()));
  log(std::to_string(buffer.pop()));
}

void test_full() {
  LockFreeCircularBuffer<int> buffer(4);
  std::vector<std::thread> producers;
  for (int i = 0; i < 4; ++i) {
    producers.emplace_back([&](){
      int count = 2;
      while (--count) {
        buffer.push(count);
      }
    });
  }
  
  std::vector<std::thread> consumers;
  for (int i = 0; i < 4; ++i) {
    consumers.emplace_back([&](){
      int count = 2;
      while (--count) {
        buffer.pop();
      }
    });
  }

  for (auto& p : producers) {
    if (p.joinable()) {
      p.join();
    }
  }
  for (auto& c : consumers) {
    if (c.joinable()) {
      c.join();
    }
  }
}

int32_t test_throughput(LockFreeCircularBuffer<int>& buffer) {
  const int payload = 1e6;
  const int threads = 8;
  auto start = std::chrono::steady_clock::now();
  // create
  std::vector<std::thread> producers;
  for (int i = 0; i < threads; ++i) {
    producers.emplace_back([&, i](){
      int count = payload + 1;
      while (--count) {
        buffer.push(count);
      }
      log("producer done: " + std::to_string(i));
    });
  }
  std::vector<std::thread> consumers;
  for (int i = 0; i < threads; ++i) {
    consumers.emplace_back([&, i](){
      int count = payload + 1;
      while (--count) {
        buffer.pop();
      }
      log("consumer done: " + std::to_string(i));
    });
  }
  for (auto& p : producers) {
    if (p.joinable()) {
      p.join();
    }
  }
  for (auto& c : consumers) {
    if (c.joinable()) {
      c.join();
    }
  }
  auto end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> duration = end - start;
  auto timecost = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
  return payload * threads / (timecost.count() * 1.0 / 1e9);
}

int main(int argc, char** argv) {
  LockFreeCircularBuffer<int> buffer(1024);
  std::atomic<bool> stop{false};
  std::thread t([&](){
    while (!stop) {
      std::cout << buffer.size() << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(2));
    }
  });
  auto res = test_throughput(buffer);
  stop.store(true);
  std::cout << "throughput: " << res << "bps" << std::endl;
  if (t.joinable()) {
    t.join();
  }
  return 0;
} 