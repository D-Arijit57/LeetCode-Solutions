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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        // creating a dummy node so that every node in the list has a node before
        ListNode dummy(0);
        dummy.next = head;

        // we need to remember before after every reversal
        // for reconnection and setting up the first pointer 
        // right next to before
        ListNode* before = &dummy;
        ListNode* first = dummy.next;
        ListNode* second = first->next;
        while(first && second){
            // we are reversing each pair at a time
            first->next = second->next;
            second->next = first;
            before->next = second;

            // set the new before after the reversal
            before = first;
            // set the new first after before
            first = before->next;
            // set the new second after first (if it exists)
            second = first ? first->next : nullptr;
        }
        return dummy.next;
    }
};