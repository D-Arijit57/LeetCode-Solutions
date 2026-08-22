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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        ListNode* slow = head;
        ListNode* fast = head;
        // phase 1: find the middle of the linkedlist
        // since we know that fast moves twice ahead of slow
        // by the time fast reaches null, slow will be at the middle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // now slow is at the middle
        // phase 2: reverse the second half of the linkedlist
        ListNode* second_half_start = slow->next;
        slow->next = nullptr;
        ListNode* curr = second_half_start;
        ListNode* prev = nullptr;
        while(curr){
          ListNode* next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
        }
        // phase 3: start from the two heads 
        // make the new connections
        ListNode* head1 = head;
        // since prev is the new head of the second half 
        ListNode* head2 = prev; 
        while(head2){
            ListNode* temp1 = head1->next;
            ListNode* temp2 = head2->next;

            head1->next = head2;
            head2->next = temp1;
            head1 = temp1;
            head2 = temp2;
        }
    }
};