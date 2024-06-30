#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int leftmost;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* node;
            queue<TreeNode*> temp;

            leftmost = q.front()->val;

            while (!q.empty()) {
                node = q.front();
                q.pop();

                if (node->left != nullptr)
                    temp.push(node->left);

                if (node->right != nullptr)
                    temp.push(node->right);
            }

            q = temp;
        }

        return leftmost;   
    }
};

int main() {

    TreeNode *root = makeTree({2,1,3});
    
    cout << "Input: root = " << root << endl;
    
    cout << "Output: " << Solution().findBottomLeftValue(root) << endl;

    return 0;
}
