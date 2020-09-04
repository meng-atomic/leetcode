#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

typedef std::vector<int>::const_iterator IteratorType;

struct BinaryTreeNode {
	BinaryTreeNode(int val = 0) : value(val), left(nullptr), right(nullptr){}
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* parent;
};

void printTreeByLevel(BinaryTreeNode* root, int level, std::map<int, std::vector<std::string>>& level_map) {
	if (root == nullptr) {
		level_map[level].push_back(std::string("*"));
		return;
	}
	level_map[level].push_back(std::to_string(root->value));
	printTreeByLevel(root->left, level + 1, level_map);
	printTreeByLevel(root->right, level + 1, level_map);
}

void printTreeByLevel(BinaryTreeNode* root) {
	std::map<int, std::vector<std::string>> level_map;
	printTreeByLevel(root, 0, level_map);
	int levels = level_map.size();
	for (auto& pair : level_map) {
		std::cout << "level " << pair.first << ": ";
		for (auto str : pair.second) {
			std::cout << str << "\t";
		}
		std::cout << std::endl;
	}
}

void preOrderTraversal(BinaryTreeNode*root, std::vector<int>& out) {
	if (root == nullptr) {
		return;
	}
	out.push_back(root->value);
	preOrderTraversal(root->left, out);
	preOrderTraversal(root->right, out);
}

void inOrderTraversal(BinaryTreeNode*root, std::vector<int>& out) {
	if (root == nullptr) {
		return;
	}
	inOrderTraversal(root->left, out);
	out.push_back(root->value);
	inOrderTraversal(root->right, out);
}

void postOrderTraversal(BinaryTreeNode*root, std::vector<int>& out) {
	if (root == nullptr) {
		return;
	}
	postOrderTraversal(root->left, out);
	postOrderTraversal(root->right, out);
	out.push_back(root->value);
}

void reconstructCore(const IteratorType& start_pre, const IteratorType& end_pre,
		const IteratorType& start_in, const IteratorType& end_in, BinaryTreeNode*& root) {
	if (start_pre >= end_pre || start_in >= end_in) {
		return;
	}
	std::cout << "pre: ";
	for (auto iter = start_pre; iter != end_pre; ++iter) {
		std::cout << *iter << ", ";
	}
	std::cout << std::endl;
	std::cout << "in: ";
	for (auto iter = start_in; iter != end_in; ++iter) {
		std::cout << *iter << ", ";
	}
	std::cout << std::endl;
	auto root_pos = std::find(start_in, end_in, *start_pre);
	if (root == nullptr) {
		root = new BinaryTreeNode(*root_pos);
		int left_tree_nodes_count = root_pos - start_in;
		reconstructCore(start_pre + 1, start_pre + left_tree_nodes_count + 1,
				start_in, root_pos, root->left);
		reconstructCore(start_pre + left_tree_nodes_count + 1, end_pre,
				root_pos + 1, end_in, root->right);
	}
}

void reconstructBinaryTree(const std::vector<int>& preOrder, const std::vector<int>& inOrder, BinaryTreeNode*& root) {
	reconstructCore(preOrder.begin(), preOrder.end(), inOrder.begin(), inOrder.end(), root);
}

BinaryTreeNode* getNext(BinaryTreeNode* root, BinaryTreeNode* node) {
	BinaryTreeNode* next = nullptr;
	if (root != nullptr && node != nullptr) {
		if (node->parent != nullptr && node->parent->left == node) {
			next = node->parent;
		} else if (node->parent != nullptr && node->parent->right == node) {
			if (node->right != nullptr) {
				next = node->right;
				while (next != nullptr && next->left != nullptr) {
					next = next->left;
				}
			} else {
				next = node->parent;
				while (next->parent != nullptr && next->parent->left != next) {
					next = next->parent;
				}
			}
		} else {
			next = node->right;
			while (next != nullptr && next->left != nullptr) {
				next = next->left;
			}
		}
	}
	return next;
}
























