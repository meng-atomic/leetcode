/*************************************************************************
*
* FORWARDX ROBOT LLC CONFIDENTIAL
* __________________
*
*  [2018] RENAISSANCE ROBOT LLC
*  All Rights Reserved.
*
* NOTICE:  All information contained herein is, and remains the property of
* Renaissance Robot LLC and its suppliers, if any. The intellectual and
* technical concepts contained herein are proprietary to Renaissance Robot LLC
* and its suppliers and may be covered by U.S. and Foreign Patents, patents in
* process, and are protected by trade secret or copyright law.
*
* Dissemination of this information or reproduction of this material is strictly
* forbidden unless prior written permission is obtained from Renaissance Robot LLC.
*
* Author: zhangmeng
*  Email: zhangmeng@forwardx.com
*   Date: Aug 31, 2020
*  Brief: A brief introduction to this file.
*          
*/

#include <iostream>
#include <stack>
#include <exception>

class CQueue {
public:
	void appendTail(int data) {
		stack1.push(data);
	}

	int deleteHead() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty()) {
			throw std::runtime_error("trying to delete element from an empty queue");
		}
		int data = stack2.top();
		stack2.pop();
		return data;
	}

private:
	std::stack<int> stack1;
	std::stack<int> stack2;
};

int main(int argc, char** argv) {
	CQueue queue;
	queue.appendTail(1);
	queue.appendTail(2);
	queue.appendTail(3);
	queue.appendTail(4);
	queue.appendTail(5);

	std::cout << queue.deleteHead() << std::endl;
	std::cout << queue.deleteHead() << std::endl;
	std::cout << queue.deleteHead() << std::endl;
	std::cout << queue.deleteHead() << std::endl;
	std::cout << queue.deleteHead() << std::endl;
}

