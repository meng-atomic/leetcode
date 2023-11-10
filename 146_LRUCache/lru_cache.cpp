#include "../utils.hpp"

struct DLinkNode {
    DLinkNode(int k = 0, int v = 0) : key(k), val(v){}
    int key{0};
    int val{0};
    DLinkNode* prev{nullptr};
    DLinkNode* next{nullptr};

    void echo() {
        auto node = this;
        while (node != nullptr) {
            std::cout << node->val << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
};

class LRUCache {
public:
  LRUCache(int max_size = 16) : 
    _max_size(max_size), _head(new DLinkNode()), _tail(new DLinkNode()){
      _head->next = _tail;
      _tail->prev = _head;
    }
  ~LRUCache(){};

  int get(int key) {
    if (_node_map.count(key) > 0) {
      move_to_head(_node_map[key]);
      return _node_map[key]->val;
    }
    return NAN;
  }

  void put(int key, int val) {
    if (_node_map.count(key) > 0) {
      return;
    }
    if (_node_map.size() >= _max_size) {
      remove_tail();
    }
    auto* new_node = new DLinkNode(key, val);
    _node_map[key] = new_node;
    move_to_head(new_node);
  }

  void echo() {
    _head->next->echo();
  }

private:
  void move_to_head(DLinkNode* node) {
    if (node == nullptr) {
      return;
    }
    if (_head->next == node) {
      return;
    }
    
    if (node->prev != nullptr) {
      node->prev->next = node->next;
    }

    if (node->next != nullptr) {
      node->next->prev = node->prev;
    }

    node->next = _head->next;
    node->prev = _head;
    _head->next = node;
    node->next->prev = node;
  }

  void remove_tail() {
    if (_tail->prev == _head) {
      return;
    }
    auto* node_rm = _tail->prev;
    node_rm->prev->next = _tail;
    _tail->prev = node_rm->prev;
    _node_map.erase(node_rm->key);
    delete node_rm;
  }

  int _max_size{16};
  DLinkNode* _head{nullptr};
  DLinkNode* _tail{nullptr};
  std::unordered_map<int, DLinkNode*> _node_map;
};

int main(int argc, char** argv) {
  LRUCache cache(64);
  cache.put(1, 101);
  cache.get(1);
  cache.echo();
  cache.put(2, 102);
  cache.put(3, 103);
  cache.put(4, 104);
  cache.put(5, 105);
  cache.get(4);
  cache.get(4);
  cache.echo();
  cache.get(3);
  cache.echo();
  return 0;
}