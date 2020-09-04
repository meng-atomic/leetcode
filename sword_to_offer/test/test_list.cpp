#include <iostream>

#include "list.hpp"

int main(int argc, char** argv) {
	ListNode* list = new ListNode();
	add(list, 1);
	add(list, 2);
	add(list, 3);
	add(list, 4);
	printList(list);
	printListRevert(list);
}
