#include <stack>
#include <iostream>
#include <set>

struct ListNode {
	ListNode(int val = 0) : value(val), next(nullptr){}
	int value;
	ListNode* next;
};

inline ListNode* add(ListNode* head, int value) {
	if (head != nullptr) {
		ListNode* tail = head;
		while (tail->next != nullptr) {
			tail = tail->next;
		}
		tail->next = new ListNode(value);
		return tail->next;
	}
	return nullptr;
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

inline void deleteNode(ListNode* list, ListNode* node) {
	if (list == nullptr || node == nullptr) {
		return;
	}
	if (node->next == nullptr) {
		ListNode* tail2 = list;
		while (tail2->next != node && tail2->next != nullptr) {
			tail2 = tail2->next;
		}
		tail2->next = nullptr;
		delete node;
		return;
	}
	ListNode* next = node->next;
	node->value = next->value;
	node->next = next->next;
	delete next;
}

void uniqueList(ListNode* list) {
	if (list == nullptr) {
		return;
	}
	std::set<int> datas = {list->value};
	ListNode* previous = list;
	ListNode* current = list->next;
	while (current != nullptr) {
		if (datas.count(current->value)) {
			delete current;
			current = current->next;
			previous->next = current;
		} else {
			datas.insert(current->value);
			previous = current;
			current = current->next;
		}
	}
}