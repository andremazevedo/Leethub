#include "../streamUtils.hpp"

using namespace std;

class Solution {
private:
    vector<int> inorder;

public:
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);

        return buildTree(0, inorder.size() - 1);
    }

private:
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);

        inorder.push_back(node->val);

        inorderTraversal(node->right);
    }

    TreeNode* buildTree(int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildTree(left, mid - 1);
        root->right = buildTree(mid + 1, right);

        return root;
    }
};

int main() {

    TreeNode* root = makeTree({1,nullopt,2,nullopt,3,nullopt,4,nullopt,nullopt});

    printInput(getName(root), root);
    
    printOutput(Solution().balanceBST(root));

    return 0;
}
