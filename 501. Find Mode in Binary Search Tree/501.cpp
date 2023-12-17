#include "../streamUtils.hpp"
#include <limits>

using namespace std;

class Solution {
private:
    vector<int> modes;
    int max = 0, frequency = 0, key = numeric_limits<int>::min();

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }

    void inorder(TreeNode* node) {
        if (node == nullptr)
            return;

        inorder(node->left);

        if (key != node->val) {
            frequency = 1;
            key = node->val;
        } 
        else {
            frequency++;
        }

        if (frequency == max) {
            modes.push_back(key);
        }
        else if (frequency > max) {
            max = frequency;
            modes = {key};
        }

        inorder(node->right);
    }
};

int main() {

    TreeNode *root = makeTree({1,NULL,2,2});
    
    cout << "Input: root = " << root << endl;
    
    cout << "Output: "<< Solution().findMode(root) << endl;

    return 0;
}
