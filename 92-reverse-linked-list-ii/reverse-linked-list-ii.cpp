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
        if(!head || !head->next) return head;

        // just to make sure every node has a node before
        ListNode dummy(0);
        dummy.next = head;

        ListNode* beforeLeft = &dummy;
        ListNode* leftPos = &dummy;
        // right pos is more right - left positions from left
        int rightPosCnt = right - left;
        int cntNodes = right - left + 1;
        // move left to its position
        // while beforeLeft follows it and stays right before it
        // make sure leftPos stays valid
        
        while(left-- && leftPos->next){
            beforeLeft = leftPos;
            leftPos = leftPos->next;
        }
        
        ListNode* rightPos = leftPos;
        while(rightPosCnt-- && rightPos->next){
            rightPos = rightPos->next;
        }
        // maintain the node afterRight for restructuring after reversal
        ListNode* afterRight = rightPos->next;
        // perform reversal of the nodes from left o right inclusive
        ListNode* curr = leftPos;
        ListNode* prev = afterRight;

        while(cntNodes--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // restructuring
        // prev becomes the new head
        beforeLeft->next = prev;

        return dummy.next;
        
    }
};