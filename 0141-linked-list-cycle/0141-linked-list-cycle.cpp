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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // to make sure that we don't end up in a infinite loop
        // check if fast and its next exists or not
        // if at any point we see that fast ends up in Null 
        // or its next is null
        // means that no cycle exists in the LL
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }

        return false;
    }
};