/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        // check if there is a cycle in the first place
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
            // if there's any cycle 
            // find the starting point 
            if(slow == fast){
                // reset slow = head (to the starting point)
                slow = head;
                // until slow and fast meets again 
                // move slow and fast by 1 place 
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};