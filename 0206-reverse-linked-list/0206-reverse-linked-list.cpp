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