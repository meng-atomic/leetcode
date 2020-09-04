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
*   Date: Aug 25, 2020
*  Brief: A brief introduction to this file.
*          
*/

#include <iostream>
#include <vector>
#include <string>
#include "binary_tree.hpp"

void printVector(const std::vector<int> vec) {
	for (auto data : vec) {
		std::cout << data << ", ";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	std::vector<int> preOrder = {1, 2, 4, 7, 3, 5, 6, 8};
	std::vector<int> inOrder = {4, 7, 2, 1, 5, 3, 8, 6};
	BinaryTreeNode* root = nullptr;
	reconstructBinaryTree(preOrder, inOrder, root);
	std::vector<int> preOrder01, inOrder01;
	preOrderTraversal(root, preOrder01);
	inOrderTraversal(root, inOrder01);
	printVector(preOrder01);
	printVector(inOrder01);
	printTreeByLevel(root);
}
