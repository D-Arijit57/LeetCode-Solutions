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
        // find the middle
        // reverse the second half 
        // start after the middle 
        // one by one connect the first one with the one from the second half
        // keep doing till you reach the end
        ListNode *slow = head;
        ListNode *fast = head;
        // Phase 1 : Find the middle of the linkedlist
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // incase of a odd length linkedlist
        ListNode* second = slow->next;
        slow->next = nullptr;
        // Phase 2 : Reverse the second half
        ListNode* curr = second;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Phase 3 : Re-ordering conecting to L0 to Ln and then so on
        ListNode* first = head;
        second = prev;
        while(second){
            // storing the next so that we can move on after swapping
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            // connecting the first with the next
            first->next = second;
            second->next = temp1;
            // moving to the next node
            first = temp1;
            second = temp2;
        }
    }
};