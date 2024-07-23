#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* mergedHead = nullptr;
        ListNode* mergedTail = nullptr;
        int sum = 0;

        for (ListNode* node = head; node != nullptr; node = node->next) {
            if (node->val == 0 && sum != 0) {
                ListNode* mergedNode = new ListNode(sum);

                if (mergedHead == nullptr)
                    mergedHead = mergedNode;
                else
                    mergedTail->next = mergedNode;

                mergedTail = mergedNode;
                sum = 0;
            }
            else {
                sum += node->val;
            }
        }

        return mergedHead;
    }
};

int main() {

    ListNode* head = makeList({0,3,1,0,4,5,2,0});
    
    printInput(getName(head), head);

    printOutput(Solution().mergeNodes(head));

    return 0;
}
