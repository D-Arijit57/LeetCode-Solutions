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
    ListNode* reverseList(ListNode* head) {
        // curr represents first of the portion of the list that is still un-processed
        // previous represents last of the portion that we just processed
        // processed == reversed
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            // save the next check point, so that we can move to the next after reversal
            ListNode* next = curr->next;
            // reconnect the current node 
            curr->next = prev;
            // the current one (already reversed) becomes the previous 
            prev = curr;
            // since we saved the checkpoint, move to it 
            curr = next;
        }
        return prev;
    }
};