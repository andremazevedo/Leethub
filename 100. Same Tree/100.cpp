#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        
        if (p == nullptr || q == nullptr || p->val != q->val)
            return false;

        if (!isSameTree(p->left, q->left))
            return false;

        if (!isSameTree(p->right, q->right))
            return false;

        return true;
    }
};

int main() {

    TreeNode *p = makeTree({2,3,1,3,1,NULL,1});
    TreeNode *q = makeTree({2,3,1,3,1,NULL,1});
    
    cout << "Input: p = " << p << ", q = " << q << endl;
    
    cout << "Output: " << boolalpha << Solution().isSameTree(p, q) << endl;

    return 0;
}
