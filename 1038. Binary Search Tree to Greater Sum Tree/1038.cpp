#include "../streamUtils.hpp"

using namespace std;

class Solution {
private:
    int sum = 0;

public:
    TreeNode* bstToGst(TreeNode* root) {
        inorderTraversal(root);

        return root;
    }

private:
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->right);

        sum += node->val;
        node->val = sum;

        inorderTraversal(node->left);
    }
};

int main() {

    TreeNode* root = makeTree({4,1,6,0,2,5,7,nullopt,nullopt,nullopt,3,nullopt,nullopt,nullopt,8});

    printInput(getName(root), root);
    
    printOutput(Solution().bstToGst(root));

    return 0;
}
