#include "../utils.hpp"

void travel_by_level(TreeNode* tree, std::map<int, std::vector<int>>& out, int level = 0) {
    if (tree == nullptr) {
        return;
    }
    travel_by_level(tree->left, out, level + 1);
    out[level].push_back(tree->val);
    travel_by_level(tree->right, out, level + 1);
}

int main(int argc, char** argv) {
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20, node15, node7);
    TreeNode* root = new TreeNode(3, node9, node20);
    std::map<int, std::vector<int>> out;
    travel_by_level(root, out);
    for (auto iter = out.begin(); iter != out.end(); ++iter) {
        echo_container(iter->second);
    }
    return 0;
}