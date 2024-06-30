#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ostream& operator<<(ostream& os, const vector<int>& vec)
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

ostream& operator<<(ostream& os, const vector<vector<int>>& matrix)
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

ostream& operator<<(ostream& os, const ListNode* head)
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

ostream& operator<<(ostream& os, const vector<ListNode*>& matrix)
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

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);

        int size = 0;
        for (ListNode* node = head; node; node = node->next) {++size;}

        int partSize = size / k;
        vector<int> sizes(k, partSize);
        for (int i = 0; i < size % k; ++i) {++sizes[i];}
        
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (node)
                res[i] = node;

            for (int j = 0; j < sizes[i] - 1; ++j) {node = node->next;}
            
            if (node) {
                ListNode* prevNode = node;
                node = node->next;
                prevNode->next = nullptr;
            }
        }

        return res;
    }
};

int main() {

    vector<int> head = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;

    ListNode *_head, *prevNode;

    for (int x : head) {
        ListNode *node = new ListNode(x);
        if (prevNode)
            prevNode->next = node;
        else
            _head = node;
        prevNode = node;
    }
    
    cout << "Input: head = " << head << ", k = " << k << endl;
    
    cout << "output: " << Solution().splitListToParts(_head, k) << endl;

    return 0;
}
