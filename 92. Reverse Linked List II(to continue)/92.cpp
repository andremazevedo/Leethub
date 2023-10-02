#include <iostream>
#include <vector>

#include "../streamUtils.hpp"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode* node = head;
        ListNode* prevNode = nullptr;

        for (; i < left; ++i) {
            prevNode = node;
            node = node->next; 
        }
        ListNode* leftHead = prevNode;
        ListNode* leftNode = node;

        for (; i < right + 1; ++i) {
            prevNode = node;
            node = node->next; 
        }
        ListNode* rightNode = prevNode;
        ListNode* rightHead = node;

        for (int j = 0; j < right - left; ++j) {
            node = leftNode;
            leftNode = leftNode->next;

            node->next = rightHead;
            rightNode->next = node;
            rightHead = node;
        }

        if (!leftHead)
            return leftNode;
        leftHead->next = leftNode;

        return head;
    }
};

int main() {

    ListNode *head = makeList({1,2,3,4,5});
    int left = 2;
    int right = 4;

    // ListNode *head = makeList({5});
    // int left = 1;
    // int right = 1;
    
    cout << "Input: head = " << head << endl;
    
    cout << "output: " << Solution().reverseBetween(head, left, right) << endl;

    return 0;
}