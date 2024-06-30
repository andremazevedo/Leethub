#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nthMinus1Node = nullptr;

        for (ListNode* node = head; node != nullptr; node = node->next) {
            if (nthMinus1Node)
                nthMinus1Node = nthMinus1Node->next;

            if (n == 0)
                nthMinus1Node = head;

            n--;
        }

        if (nthMinus1Node == nullptr)
            head = head->next;
        else if (nthMinus1Node->next == nullptr)
            nthMinus1Node->next = nullptr;
        else
            nthMinus1Node->next = nthMinus1Node->next->next;
        
        return head;
    }
};

int main() {

    ListNode* head = makeList({1});
    int n = 1;
    
    cout << "Input: head = " << head << ", n = " << n << endl;
    
    cout << "Output: "<< Solution().removeNthFromEnd(head, n) << endl;

    return 0;
}
