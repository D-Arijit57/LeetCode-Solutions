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
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        // Phase 1 : find the middle of the linkedlist
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        // Remove slow or there would be a dangling pointer issue 
        slow->next = nullptr;
        // Phase 2 : Reverse the second half 
        ListNode* curr = mid;
        ListNode* prev = nullptr;
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Phase 3 : Create the re order of the linkedlist
        ListNode* head1 = head;
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