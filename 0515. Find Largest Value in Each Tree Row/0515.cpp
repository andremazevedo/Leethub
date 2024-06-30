#include "../streamUtils.hpp"
#include <limits>

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> values;
        int val = numeric_limits<int>::min();
        queue<TreeNode*> q;
        queue<TreeNode*> nextQ;

        if (root) {
            q.push(root);
        }
        
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if (node->val > val) {
                val = node->val;
            }

            if (node->left != nullptr) {
                nextQ.push(node->left);
            }
            
            if (node->right  != nullptr) {
                nextQ.push(node->right);
            }

            if (q.empty()) {
                values.push_back(val);
                val = numeric_limits<int>::min();
                q = nextQ;
                nextQ = {};
            }
            
        }
        
        return values;
    }
};

int main() {

    vector<int> vec = {1,3,2,5,3,NULL,9};
    TreeNode *root = makeTree(vec);
    
    cout << "Input: root = " << vec << endl;
    
    cout << "Output: "<< Solution().largestValues(root) << endl;

    return 0;
}
