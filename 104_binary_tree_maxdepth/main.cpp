#include "../utils.hpp"

int max_depth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return std::max(max_depth(root->left),max_depth(root->right)) + 1;
}

int main(int argc, char** argv) {
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20, node15, node7);
    TreeNode* root = new TreeNode(3, node9, node20);
    node15->left = new TreeNode(8);
    node15->left->right = new TreeNode(9);
    node15->left->right->left = new TreeNode(10);
    std::cout << max_depth(root) << std::endl;
    return 0;
}