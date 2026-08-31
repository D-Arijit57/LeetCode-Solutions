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
     ListNode* slow = head;
     ListNode* fast = head;
     while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        // when the slow and fast meet 
        // we set the slow to the head
        if(slow == fast){
            // since the distance between meeting point inside the cycle to the end of the list and from head to the start of cycle 
            // the two pointers are bound to meet
            slow = head;
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