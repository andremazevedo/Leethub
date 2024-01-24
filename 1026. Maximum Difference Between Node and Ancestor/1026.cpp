#include "../streamUtils.hpp"

using namespace std;

class Solution {
private:
    vector<TreeNode*> ancestors;
    int max = 0;

    int dfs(TreeNode* node) {
        if (node == nullptr)
            return 0;

        for (auto ancestor : ancestors)
            if (abs(ancestor->val - node->val) > max)
                max = abs(ancestor->val - node->val);

        ancestors.push_back(node);

        dfs(node->left);

        dfs(node->right);

        ancestors.erase(remove(ancestors.begin(), ancestors.end(), node), ancestors.end());

        return max;
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root);
    }
};

int main() {

    TreeNode *root = makeTree({8,3,10,1,6,NULL,14,NULL,NULL,4,7,13});
    
    cout << "Input: root = " << root << endl;
    
    cout << "Output: " << Solution().maxAncestorDiff(root) << endl;

    return 0;
}
