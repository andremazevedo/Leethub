#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
 
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *node = head;
        for (int i = 0; i <= 10000; ++i) {
            if (node == NULL)
                return false;
            node = node->next;
        }
        return true;
    }
};

int main() {

    vector<int> head = {3,2,0,-4};
    int pos = 1;

    ListNode *_head, *node;

    for (int x : head) {
        ListNode *newNode = new ListNode(x);
        if (node)
            node->next = newNode;
        else
            _head = newNode;
        node = newNode;
    }

    if (pos != -1) {
        ListNode *_node = _head;
        for (int i = 0; i < pos; ++i)
            _node = _node->next;
        node->next = _node;
    }
    
    cout << "Input: head = " << head << ", pos = " << pos << endl;
    
    cout << "output: " << Solution().hasCycle(_head) << endl;

    return 0;

}
