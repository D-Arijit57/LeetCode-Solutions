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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // solve it up with two pointers
       ListNode dummy(0);
       dummy.next = head;
       ListNode* slow = &dummy;
       ListNode* fast = &dummy;
       // set fast n+1 nodes ahead of slow
       for(int i = 0 ; i < n + 1 ; i++){
        fast = fast->next;
       }
       // now move slow and fast together
       while(fast){
        slow = slow->next;
        fast = fast->next;
       }
       // when fast reaches null 
       // slow will be the pointer just before the target
       ListNode* target = slow->next;
       slow->next = target->next;
       target->next = nullptr;
       delete target;
       return dummy.next;
    }
};