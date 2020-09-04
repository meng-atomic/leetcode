#include <stack>

struct ListNode {
	ListNode(int val = 0) : value(val), next(nullptr){}
	int value;
	ListNode* next;
};

inline void add(ListNode* head, int value) {
	if (head != nullptr) {
		ListNode* tail = head;
		while (tail->next != nullptr) {
			tail = tail->next;
		}
		tail->next = new ListNode(value);
	}
}

inline void printList(ListNode* head) {
	while (head != nullptr) {
		std::cout << head->value << ", ";
		head = head->next;
	}
	std::cout << std::endl;
}

inline void printListRevert(ListNode* head) {
	std::stack<int> deq;
	ListNode* cur = head;
	while (cur != nullptr) {
		deq.push(cur->value);
		cur = cur->next;
	}
	while(!deq.empty()) {
		std::cout << deq.top() << ", ";
		deq.pop();
	}
	std::cout << std::endl;
}
