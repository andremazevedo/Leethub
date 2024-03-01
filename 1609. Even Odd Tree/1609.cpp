#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool evenLevel = true;

        q.push(root);

        while (!q.empty()) {
            TreeNode* node;
            int n = q.size();
            int minMax = 0;

            for (int i = 0; i < n; i++) {
                node = q.front();
                q.pop();

                if (evenLevel && (node->val % 2 == 0 || node->val <= minMax))
                    return false;
                else if (!evenLevel && (node->val % 2 != 0 || (minMax != 0 && node->val >= minMax)))
                    return false;

                minMax = node->val;

                if (node->left != nullptr)
                    q.push(node->left);

                if (node->right != nullptr)
                    q.push(node->right);
            }

            evenLevel = !evenLevel;
        }

        return true;
    }
};

int main() {

    TreeNode *root = makeTree({1,10,4,3,NULL,7,9,12,8,6,NULL,NULL,2});
    
    cout << "Input: root = " << root << endl;
    
    cout << "Output: " << boolalpha << Solution().isEvenOddTree(root) << endl;

    return 0;
}
