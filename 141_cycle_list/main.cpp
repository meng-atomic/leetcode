#include "../utils.hpp"

bool hasCycle(ListNode *head) {
  std::unordered_set<ListNode*> node_set;
  ListNode* node = head;
  while (node != nullptr) {
    if (node_set.count(node) > 0) {
      return true;
    }
    node_set.insert(node);
    node = node->next;
  }
  
  return false;
}

int main(int argc, char** argv) {
  ListNode* head = new ListNode(3);
  ListNode* node2 = new ListNode(2);
  ListNode* node0 = new ListNode(0);
  ListNode* node_4 = new ListNode(-4);
  head->next = node2;
  node2->next = head;
  node0->next = node_4;
  node_4->next = node2;
  bool res = hasCycle(head);
  std::cout << std::boolalpha << res << std::endl;
  return 0;
}