#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        
        traverseTree(root, &diameter);

        return diameter;
    }

    int traverseTree(TreeNode* node, int* diameter) {
        if (node == nullptr)
            return 0;

        int left = traverseTree(node->left, diameter);

        int right = traverseTree(node->right, diameter);

        if (left + right > *diameter)
            *diameter = left + right;
        
        return max(left + 1, right + 1);
    }
};

int main() {

    TreeNode *root = makeTree({1,2,3,4,5});
    
    cout << "Input: root = " << root << endl;
    
    cout << "Output: " << Solution().diameterOfBinaryTree(root) << endl;

    return 0;
}