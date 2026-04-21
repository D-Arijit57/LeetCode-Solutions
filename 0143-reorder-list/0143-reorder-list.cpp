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
        // find the middle of the linkedlist
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // move the slow to the next node of the middle
        ListNode* second = slow->next;
        slow->next = nullptr;

        // reverse the linkedlist
        ListNode* curr = second;
        ListNode* prev = nullptr;
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // split into two heads
        ListNode* head1 = head;
        ListNode* head2 = prev;

        // until head2 reaches the end 
        // we have to run the algorithm 
        while(head2){
            ListNode* temp1 = head1->next;
            ListNode* temp2 = head2->next;

            // building the pattern
            head1->next = head2;
            head2->next = temp1;
            head1 = temp1;
            head2 = temp2;
        }

    }
};