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
        if(!head) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        // finding the middle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // in case if the linkedlist has an odd length 
        if(fast!=nullptr) slow = slow->next;
        ListNode* curr = slow;
        ListNode* prev = nullptr;
        ListNode* next;
        // reverse the linkedlist
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // compare the second half with the first half
        ListNode* first = head;
        ListNode* second = prev;
        while(second){
            if(first->val != second->val) return false;
            else {
                first = first->next;
                second = second->next;
            }
        }
        return true;
    }
};