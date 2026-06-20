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
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is pointing to the middle node now
        // point to the second half (just after slow)
        ListNode* second = slow->next;
        // remove the slow pointer
        slow->next = nullptr;
        // reverse the second half
        ListNode* curr = second;
        ListNode* prev = nullptr;
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // create new head
        // keep on connecting old and new nodes 
        // to form the pattern 
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