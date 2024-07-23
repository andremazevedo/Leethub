#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> answer = {-1,-1};
        int minDistance = INT_MAX;
        ListNode* left = head, *node = head->next, *right = head->next->next;
        int pointCount = 0;
        int firstCriticalPoint = -1, lastCriticalPoint = -1;

        while (right != nullptr) {
            if (left->val < node->val && node->val > right->val || left->val > node->val && node->val < right->val) {
                if (firstCriticalPoint == -1)
                    firstCriticalPoint = pointCount;
                else
                    minDistance = min(minDistance, pointCount - lastCriticalPoint);

                lastCriticalPoint = pointCount;
            }

            left = node, node = right, right = right->next;
            pointCount++;
        }

        if (firstCriticalPoint != lastCriticalPoint)
            answer = {minDistance, lastCriticalPoint - firstCriticalPoint};

        return answer;
    }
};

int main() {

    ListNode* head = makeList({5,3,1,2,5,1,2});
    
    printInput(getName(head), head);

    printOutput(Solution().nodesBetweenCriticalPoints(head));

    return 0;
}
