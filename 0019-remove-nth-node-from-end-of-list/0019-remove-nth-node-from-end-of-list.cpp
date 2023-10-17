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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Two pointer approach :
        // slow and fast pointer initialization 
        ListNode* slow = head , *fast = head;
        // until we reach the nth posisiton move the fast pointer 
        while(n--){ 
            fast = fast -> next;
        }
        // if the fast pointer is now pointing the null pointer move the slow pointer 
        if(fast == NULL){
            return slow -> next;
        }
        // until fast reaches NULL move fast and slow pointer 
        while( fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        // initialize the slow's next as the next of next of slow 
        slow -> next = slow -> next -> next;
        return head;
    }
};