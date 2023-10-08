#include <iostream>
#include <vector>
#include <stack>
#include "../utils.hpp"

ListNode* reverse(ListNode* head) {
    std::stack<ListNode*> stack;
    auto& node = head;
    while (node != nullptr) {
        stack.emplace(node);
        node = node->next;
    }
    if (stack.empty()) {
        return head;
    }
    ListNode* rev_head = stack.top();
    ListNode* curr_node = rev_head;
    stack.pop();
    while (!stack.empty()) {
        curr_node->next = stack.top();
        curr_node = stack.top();
        curr_node->next = nullptr;
        stack.pop();
    }
    return rev_head;
}

ListNode* reverse1(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = head->next;
    while (next != nullptr) {
        ListNode* tmp_node = next->next;
        curr->next = prev;
        next->next = curr;
        prev = curr;
        curr = next;
        next = tmp_node;
    }
    return curr;
}

int main(int argc, char** argv) {
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    std::cout << head;
    auto rev_head = reverse1(head);
    std::cout << rev_head;
    auto rev_rev_head = reverse(rev_head);
    std::cout << rev_rev_head;
    return 0;
}