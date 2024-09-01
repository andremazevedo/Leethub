#include "../streamUtils.hpp"

class Solution {
private:
    vector<int> answer;

    void postorderTraversal(Node* node) {
        for (Node *children : node->children)
            postorderTraversal(children);
        
        answer.push_back(node->val);
    }

public:
    vector<int> postorder(Node* root) {
        if (root == nullptr)
            return {};
        
        postorderTraversal(root);

        return answer;
    }
};

int main() {
    Node* root = new Node(1);
    Node* node = new Node(3);
    root->children.push_back(node);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    node->children.push_back(new Node(5));
    node->children.push_back(new Node(6));

    printOutput(Solution().postorder(root));

    return 0;
}
