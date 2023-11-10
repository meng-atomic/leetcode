#include "../utils.hpp"
#include <list>

class MedianFinder {
public:
    MedianFinder() {
        std::make_heap(_left_datas.begin(), _left_datas.end(), std::less<int>{});
        std::make_heap(_right_datas.begin(), _right_datas.end(), std::greater<int>{});
    }
    
    void addNum(int num) {
        if (!_right_datas.empty() && num >= _right_datas.front()) {
            _right_datas.push_back(num);
            std::push_heap(_right_datas.begin(), _right_datas.end(), std::greater<int>{});      
        } else {
            _left_datas.push_back(num);
            std::push_heap(_left_datas.begin(), _left_datas.end());
        }
        if ((_left_datas.size() > _right_datas.size()) && (_left_datas.size() - _right_datas.size() > 1)) {
            _right_datas.push_back(_left_datas.front());
            std::push_heap(_right_datas.begin(), _right_datas.end(), std::greater<int>{});
            _left_datas.erase(_left_datas.begin());
        } else if ((_right_datas.size() > _left_datas.size()) && (_right_datas.size() - _left_datas.size() > 1)) {
            _left_datas.push_back(_right_datas.front());
            std::push_heap(_left_datas.begin(), _left_datas.end());
            _right_datas.erase(_right_datas.begin());
        }
    }
    
    double findMedian() {
        if (_left_datas.size() == 0 && _right_datas.size() == 0) {
            return MAXFLOAT;
        } 
        if (_left_datas.size() == _right_datas.size()) {
            return (_left_datas.front() + _right_datas.front()) / 2.0;
        }
        if (_left_datas.size() > _right_datas.size()) {
            return _left_datas.front();
        }
        if (_right_datas.size() > _left_datas.size()) {
            return _right_datas.front();
        }
        return MAXFLOAT;
    }

    void echo() {
        echo_container(_left_datas);
        echo_container(_right_datas);
    }

private:
    std::vector<int> _left_datas;
    std::vector<int> _right_datas;
};

class MF {
public:
  void addNum(int num) {
    if (_left_datas.size() > _right_datas.size()) {
      if (_right_datas.empty()) {
        _right_datas.push_back(num);
        return;
      }
      if (num < _right_datas.front()) {
        _right_datas.push_front(num);
      } else {
        _right_datas.push_back(num);
      }
    } else {
      if (_left_datas.empty()) {
        _left_datas.push_back(num);
        return;
      }
      if (num > _left_datas.back()) {
        _left_datas.push_back(num);
      } else {
        _left_datas.push_front(num);
      }
    }
  }

  double findMedian() {
    if (_left_datas.size() == 0 && _right_datas.size() == 0) {
      return MAXFLOAT;
    }
    if (_left_datas.size() == _right_datas.size()) {
      return (_left_datas.back() + _right_datas.front()) / 2.0;
    }
    if (_left_datas.size() > _right_datas.size()) {
      return _left_datas.back();
    }
    if (_right_datas.size() > _left_datas.size()) {
      return _right_datas.front();
    }
  }


  void echo() {
    echo_container(_left_datas);
    echo_container(_right_datas);
  }

private:
  std::list<int> _left_datas;
  std::list<int> _right_datas;
};

int main(int argc, char** argv) {
    MF finder;
    finder.addNum(1);
    finder.echo();
    std::cout << finder.findMedian() << std::endl;
    finder.addNum(4);
    finder.echo();
    std::cout << finder.findMedian() << std::endl;
    finder.addNum(3);
    finder.echo();
    std::cout << finder.findMedian() << std::endl;
    finder.addNum(5);
    finder.echo();
    std::cout << finder.findMedian() << std::endl;
    finder.addNum(2);
    finder.echo();
    std::cout << finder.findMedian() << std::endl;
    return 0;
}