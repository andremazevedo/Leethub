#include "../streamUtils.hpp"

using namespace std;

class Solution {
private:
    int paths = 0;

    void dfs(TreeNode* node, int bitmask) {
        bitmask ^= (1 << node->val);
        
        if (node->left != nullptr)
            dfs(node->left, bitmask);

        if (node->right != nullptr)
            dfs(node->right, bitmask);

        if (node->left == nullptr && node->right == nullptr)
            if ((bitmask == 0) || ((bitmask & (bitmask - 1)) == 0))
                paths++;
    }

public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int bitmask = 0;

        dfs(root, bitmask);
        
        return paths;
    }
};

int main() {

    TreeNode *root = makeTree({2,3,1,3,1,NULL,1});
    
    cout << "Input: root = " << root << endl;
    
    cout << "Output: " << Solution().pseudoPalindromicPaths(root) << endl;

    return 0;
}
