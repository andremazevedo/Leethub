#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (node !=  nullptr) {
                if (low <= node->val && node->val <= high) {
                    sum += node->val;
                }

                if (low <= node->val) {
                    s.push(node->left);
                }

                if (node->val <= high) {
                    s.push(node->right);
                }
            }
        } 

        return sum;
    }
};

int main() {

    TreeNode *root = makeTree({10,5,15,3,7,NULL,18});
    int low = 7; 
    int high = 15;
    
    cout << "Input: root = " << root << ", low = " << low << ", high = " << high  << endl;
    
    cout << "Output: " << Solution().rangeSumBST(root, low, high) << endl;

    return 0;
}
