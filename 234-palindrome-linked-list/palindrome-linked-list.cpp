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
     if(!head || !head->next) return true;
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
        // Reversing the second half 
        while(curr != nullptr){
            // temporarily storing the next node to be reversed
            // to access it after reversing the current node 
            ListNode* next = curr->next;
            // connect the next pointer to the previous node
            // prev becomes curr since its has already been reversed 
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // comparing the first half with the second half 
        ListNode* first = head;
        ListNode* second = prev;
        // since the second part actually defines if its a palindrome or not
        // meaning it would define how many comparisons are supposed to be done 
        while(second != nullptr){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};