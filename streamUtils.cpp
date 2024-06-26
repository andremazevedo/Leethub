#include "streamUtils.hpp"

std::ostream& operator<<(std::ostream& os, const ListNode* head)
{
    os << "[";
    for (const ListNode* node = head; node != nullptr; node = node->next) {
        os << node->val;
        if (node->next != nullptr) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

ListNode* makeList(const std::vector<int>& vec) 
{
    ListNode *head = nullptr, *prev = nullptr;
    for (int x : vec) {
        ListNode *node = new ListNode(x);
        if (prev)
            prev->next = node;
        else
            head = node;
        prev = node;
    }
    return head;
}

std::ostream& operator<<(std::ostream& os, const TreeNode* root)
{
    std::vector<std::optional<int>> vec;
    std::queue<TreeNode*> q;

    if (root != nullptr) {
        vec.push_back(root->val);
        q.push((TreeNode*)root);
    }

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node->left) {
            vec.push_back(node->left->val);
            q.push(node->left);
        } else {
            vec.push_back(std::nullopt);
        }

        if (node->right) {
            vec.push_back(node->right->val);
            q.push(node->right);
        } else {
            vec.push_back(std::nullopt);
        }
    }

    while (!vec.empty() && !vec.back().has_value()) {
        vec.pop_back();
    }

    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].has_value()) {
            os << vec[i].value();
        } else {
            os << "null";
        }

        if (i < vec.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

TreeNode* makeTree(const std::vector<std::optional<int>>& vec)
{
    TreeNode *root = nullptr;
    std::queue<TreeNode*> q;

    if (vec.empty()) {
        return root;
    }

    root = new TreeNode(vec.front().value());
    q.push(root);

    for (int i = 1; i < vec.size(); i += 2) {
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        TreeNode *node = q.front();
        q.pop();

        if (vec[i].has_value()) {
            left = new TreeNode(vec[i].value());
            q.push(left);
        }
        node->left = left;

        if (i + 1 < vec.size() && vec[i + 1].has_value()) {
            right = new TreeNode(vec[i + 1].value());
            q.push(right);
        }
        node->right = right;
    }

    return root;
}
