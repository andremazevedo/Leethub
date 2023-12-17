#include "streamUtils.hpp"

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec)
{
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& matrix)
{
    os << "[";
    for (size_t row = 0; row < matrix.size(); ++row) {
        os << matrix[row];
        if (row < matrix.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<double>>& matrix)
{
    os << "[";
    for (size_t row = 0; row < matrix.size(); ++row) {
        os << matrix[row];
        if (row < matrix.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec)
{
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

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
    std::queue<TreeNode*> q;
    os << "[";

    if (root != nullptr) {
        os << root->val;
        if (root->left != nullptr || root->right != nullptr) {
            q.push((TreeNode*) root);
        }
    }

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node->left != nullptr) {
            if (node->left->left != nullptr || node->left->right != nullptr) {
                q.push(node->left);
            }
            os << ",";
            os << node->left->val;
        } else {
            os << ",";
            os << "null";
        }

        if (node->right != nullptr) {
            if (node->right->left != nullptr || node->right->right != nullptr) {
                q.push(node->right);
            }
            os << ",";
            os << node->right->val;
        } else if (!q.empty()) {
            os << ",";
            os << "null";
        }
    }

    os << "]";
    return os;
}

TreeNode* makeTree(const std::vector<int>& vec)
{
    TreeNode *root = nullptr;
    std::queue<TreeNode*> q;

    if (!vec.empty()) {
        root = new TreeNode(vec[0]);
        q.push(root);
    }

    for (int i = 1; i < vec.size(); i += 2) {
        TreeNode *node = q.front();
        q.pop();

        if (vec[i]) {
            node->left = new TreeNode(vec[i]);
            q.push(node->left);
        }

        if (vec[i + 1]) {
            node->right = new TreeNode(vec[i + 1]);
            q.push(node->right);
        }
    }

    return root;
}