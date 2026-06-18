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
        // edge case : range is only 1 node 
        if(left == right) return head;
        // find out the leftNode and the node before the left
        ListNode dummy(0);
        dummy.next = head;
        ListNode* beforeLeft = &dummy;
        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }
        ListNode* leftNode = beforeLeft->next;

        // reverse till right - left + 1
        int cnt = right - left + 1;
        ListNode* curr = leftNode;
        ListNode* prev = nullptr;
        ListNode* next;
        while (cnt--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // connect the two ends
        // after the reversal
        // prev becomes the new head of the reversed section
        // curr becomes the node right after the end of the section
        beforeLeft->next = prev;
        leftNode->next = curr;

        return dummy.next;
    }
};