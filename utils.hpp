#pragma once
#include <random>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>

template<typename C>
void echo_container(const C& vec) {
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << ",";
    }
    std::cout << std::endl;
}

std::vector<int> random_generator(int size, int min, int max) {
    std::vector<int> res;
    static std::random_device r;
    static std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(min, max);
    for (int i = 0; i < size; ++i) {
        res.emplace_back(uniform_dist(e1));
    }
    return res;
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline std::ostream& operator<<(std::ostream& os, const ListNode* list) {
    auto node = list;
    while (node != nullptr) {
        os << node->val << ",";
        node = node->next;
    }
    os << std::endl;
    return os;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
