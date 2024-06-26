#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root1);
        s2.push(root2);

        while (!s1.empty() && !s2.empty()) {
            TreeNode* node1 = s1.top();
            TreeNode* node2 = s2.top();
            s1.pop();
            s2.pop();

            while (node1->left != nullptr || node1->right != nullptr) {
                if (node1->right != nullptr)
                    s1.push(node1->right);

                if (node1->left != nullptr)
                    s1.push(node1->left);

                node1 = s1.top();
                s1.pop();
            }

            while (node2->left != nullptr || node2->right != nullptr) {
                if (node2->right != nullptr)
                    s2.push(node2->right);

                if (node2->left != nullptr)
                    s2.push(node2->left);
                
                node2 = s2.top();
                s2.pop();
            }

            if (node1->val != node2->val)
                return false;
        }

        if (!s1.empty() || !s2.empty()) 
            return false;
        else
            return true;
    }
};

int main() {

    TreeNode *root1 = makeTree({3,5,1,6,2,9,8,nullopt,nullopt,7,4});
    TreeNode *root2 = makeTree({3,5,1,6,7,4,2,nullopt,nullopt,nullopt,nullopt,nullopt,nullopt,9,8});
    
    printInput(getName(root1), root1, getName(root2), root2);
    
    printOutput(Solution().leafSimilar(root1, root2));

    return 0;
}
