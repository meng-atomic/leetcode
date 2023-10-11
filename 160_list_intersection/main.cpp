#include "../utils.hpp"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::cout << headA << std::endl;
    std::cout << headB << std::endl;
    auto nodeA = headA;
    int a_length = 0;
    while (nodeA != nullptr) {
        ++a_length;
        nodeA = nodeA->next;
    }
    auto nodeB = headB;
    int b_length = 0;
    while (nodeB != nullptr) {
        ++b_length;
        nodeB = nodeB->next;
    }
    auto long_list = headA;
    auto short_list = headB;
    if (a_length < b_length) {
        std::swap(long_list, short_list);
    }
    std::cout << "long_list: " << long_list->val << ", short_list: " << short_list->val << std::endl;
    auto lnode = long_list;
    auto snode = short_list;
    int skip = abs(int(a_length - b_length));
    std::cout << "a_length: " << a_length << ", b_length: " << b_length << std::endl;
    std::cout << "skip: " << skip << std::endl;
    while (--skip >= 0 && lnode != nullptr) {
        std::cout << "skipping " << lnode->val << std::endl;
        lnode = lnode->next;
    }
    while (lnode != nullptr && snode != nullptr) {
        if (lnode == snode) {
            return lnode;
        }
        std::cout << "current: " << lnode->val << ", " << snode->val << std::endl;
        lnode = lnode->next;
        snode = snode->next;
    }
    return nullptr;
}

int main(int argc, char** argv) {
    ListNode* headA = new ListNode(4);
    ListNode* headB = new ListNode(5);
    ListNode* nodeA_1 = new ListNode(1);
    ListNode* node8 = new ListNode(8);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* nodeB6 = new ListNode(6);
    ListNode* nodeB1 = new ListNode(1);
    
    headA->next = nodeA_1;
    nodeA_1->next = node8;
    headB->next = nodeB6;
    nodeB6->next = nodeB1;
    nodeB1->next = node8;
    node8->next = node4;
    node4->next = node5;

    auto intersec_node = getIntersectionNode(headA, headB);
    if (intersec_node == nullptr) {
        std::cout << "no intersection" << std::endl;
    } else {
        std::cout << "intersection: " << intersec_node->val << std::endl;
    }

    return 0;
}