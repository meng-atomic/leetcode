#include <iostream>

#include "list.hpp"

int main(int argc, char** argv) {
	ListNode* list = new ListNode(1);
	auto node1 = add(list, 1);
	auto node2 = add(list, 2);
	auto node3 = add(list, 5);
	auto node4 = add(list, 3);
	auto node5 = add(list, 7);
	auto node6 = add(list, 3);
	add(list, 5);
	printList(list);
	// deleteNode(list, node6);
	// printList(list);
	uniqueList(list);
	printList(list);
	// printListRevert(list);
}
