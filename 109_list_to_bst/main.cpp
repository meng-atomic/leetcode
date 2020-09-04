#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ListNode* getMidNode(ListNode* left, ListNode* right) {
	ListNode* fast = left;
	ListNode* slow = left;
	while (fast != nullptr && fast != right && fast->next != right) {
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

TreeNode* buildTree(ListNode* left, ListNode* right) {
	if (left == right) {
		return nullptr;
	}
	ListNode* mid = getMidNode(left, right);
	TreeNode* root = new TreeNode(mid->val);
	root->left = buildTree(left, mid);
	root->right = buildTree(mid->next, right);
	return root;
}

TreeNode* sortedListToBST(ListNode* head) {
	return buildTree(head, nullptr);
}

void addNode(ListNode* head, int val) {
	ListNode* node = new ListNode(val);
	ListNode* tail = head;
	while (tail != nullptr && tail->next != nullptr) {
		tail = tail->next;
	}
	if (tail != nullptr) {
		tail->next = node;
	}
}

void printList(ListNode* head) {
	while (head != nullptr) {
		std::cout << head->val << ", ";
		head = head->next;
	}
	std::cout << std::endl;
}

void iterateTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	iterateTree(root->left);
	std::cout << root->val << ", ";
	iterateTree(root->right);
}

int treeNodeCount(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	return treeNodeCount(root->left) + treeNodeCount(root->right) + 1;
}

TreeNode* buildTree(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNode* list_node = head;
	TreeNode* root = new TreeNode();
	std::queue<TreeNode*> que;
	que.push(root);
	list_node = list_node->next;
	while (list_node != nullptr) {
		TreeNode* node = que.front();
		que.pop();
		node->left = new TreeNode();
		que.push(node->left);
		list_node = list_node->next;
		if (list_node == nullptr) {
			break;
		}
		node->right = new TreeNode();
		que.push(node->right);
		list_node = list_node->next;
	}
	return root;
}

void printTreeByLevel(TreeNode* root) {
	std::map<int, std::vector<std::string>> level_map;
	printTreeByLevel(root, 0, level_map);
	for (auto& pair : level_map) {
		std::cout << "level " << pair.first << ": ";
		for (auto str : pair.second) {
			std::cout << str << "\t";
		}
		std::cout << std::endl;
	}
}

void printTreeByLevel(TreeNode* root, int level, std::map<int, std::vector<std::string>>& level_map) {
	if (root == nullptr) {
		level_map[level].push_back(std::string("*"));
		return;
	}
	level_map[level].push_back(std::to_string(root->val));
	printTreeByLevel(root->left, level + 1, level_map);
	printTreeByLevel(root->right, level + 1, level_map);
}

int main(int argc, char** argv) {
	ListNode* head = new ListNode(0);
	for (int i = 1; i < 7; ++i) {
		addNode(head, i);
	}

	printList(head);

	TreeNode* root = buildTree(head);

//	TreeNode* root = sortedListToBST(head);
//	iterateTree(root);
//	std::cout << std::endl;
//	std::cout << "node on tree: " << treeNodeCount(root) << std::endl;

	std::map<int, std::vector<std::string>> level_map;
	printTreeByLevel(root, 0, level_map);

	for (auto& pair : level_map) {
		std::cout << "level " << pair.first << ": ";
		for (auto str : pair.second) {
			std::cout << str << "\t";
		}
		std::cout << std::endl;
	}
}
