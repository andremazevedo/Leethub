#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> originalToCopyMap;

        for (Node* node = head; node != NULL; node = node->next) {
            originalToCopyMap[node] = new Node(node->val);
        }

        for (Node* node = head; node != NULL; node = node->next) {
            Node* copyNode = originalToCopyMap[node];
            copyNode->next = originalToCopyMap[node->next];
            copyNode->random = originalToCopyMap[node->random];
        }

        return originalToCopyMap[head];
    }
};

int main() {

    vector<vector<int>> head = {{7,-1},{13,0},{11,4},{10,2},{1,0}};

    Node* _head, * prevNode = NULL, * newNode;
    for (vector<int> i : head) {
        newNode = new Node(i[0]);
        if (prevNode)
            prevNode->next = newNode;
        else
            _head = newNode;
        prevNode = newNode;
    }

    int i = 0;
    for (Node* node = _head; node != NULL; node = node->next, ++i) {
        if (head[i][1] == -1)
            continue;

        Node* random = _head;
        for (int j = 0; j < head[i][1]; ++j) {
            random = random->next;
        }
        node->random = random;
    }
    
    cout << "Input: head = " << head << endl;
    
    // cout << "output: " << Solution().copyRandomList(_head) << endl;
    Solution().copyRandomList(_head);

    return 0;

}