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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;
        // we can't just directly delete the middle node
        // we have to establish the connect between the node before and after it
        // use slow and fast pointer to find the middle of the linkedlist
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // to mark the node just before the slow
        // find the middle fo the linkedlist
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // middle of the ll
        ListNode* deleteNode = slow;
        // mark the node after the middle
        ListNode* nodeAfterMiddle = slow->next;
        prev->next = nodeAfterMiddle;
        slow->next = nullptr;
        delete slow;
        return head;
        
    }
};