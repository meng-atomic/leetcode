#include "../utils.hpp"

struct DLinkNode {
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
    LRUCache(int max_size = 16) : _max_size(max_size) {
        _head->next = _tail;
        _tail->prev = _head;
    }
    ~LRUCache(){}

    int get(int key) {
        if (_node_map.count(key) == 0) {
            return INT32_MAX;
        }
        auto node = _node_map[key];
        if (node == nullptr) {
            return INT32_MAX;
        }
        move_to_head(node);
        return node->val;
    }

    void put(int key, int val) {
        auto iter = _node_map.find(key);
        if (iter != _node_map.end()) {
            return;
        }
        if (_node_map.size() >= _max_size) {
            pop_back();
        }
        DLinkNode* new_node = new DLinkNode();
        new_node->key = key;
        new_node->val = val;
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

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }

        node->next = _head->next;
        _head->next->prev = node;
        _head->next = node;
        node->prev = _head;
    }

    void pop_back() {
        if (_node_map.size() == 0) {
            return;
        }
        auto node = _tail->prev;
        if (node == nullptr) {
            return;
        }
        _tail->prev = node->prev;
        node->prev->next = _tail;
        _node_map.erase(node->val);
        delete node;
    }

    DLinkNode* _head{new DLinkNode()};
    DLinkNode* _tail{new DLinkNode()};
    std::map<int, DLinkNode*> _node_map;
    const int _max_size;
};

int main(int argc, char** argv) {
    LRUCache cache(8);
    cache.echo();
    cache.get(6);
    cache.echo();
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
    return 0;
}