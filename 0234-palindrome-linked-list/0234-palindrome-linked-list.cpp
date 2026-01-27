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
    bool isPalindrome(ListNode* head) {
     ListNode* slow = head;
     ListNode* fast = head;
     // first phase finding the middle of the linked list
     while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        }
        // if its a odd position skip it 
        if(fast != nullptr) slow = slow->next;
        // since we need to reverse the ll in place we are going to use curr, prev and next
        // reversing before the middle part
        ListNode* curr = slow;
        ListNode* prev = nullptr; 
        ListNode* next;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // comparing the first half with the second half 
        ListNode* first = head;
        ListNode* second = prev;
        while(second != nullptr){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};