#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (node->left != nullptr) {
                if (node->left->left == nullptr && node->left->right == nullptr)
                    sum += node->left->val;
                else
                    s.push(node->left);
            }

            if (node->right != nullptr) {
                s.push(node->right);
            }
        }
        
        return sum;
    }
};

int main() {

    TreeNode* root = makeTree({3,9,20,nullopt,nullopt,15,7});

    printInput(getName(root), root);
    
    printOutput(Solution().sumOfLeftLeaves(root));

    return 0;
}
