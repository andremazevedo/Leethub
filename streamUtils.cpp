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

ListNode* makeList(const std::vector<int>& vec) {
    ListNode *head = nullptr, *prevNode = nullptr;
    for (int x : vec) {
        ListNode *node = new ListNode(x);
        if (prevNode)
            prevNode->next = node;
        else
            head = node;
        prevNode = node;
    }
    return head;
}