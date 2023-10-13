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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head -> next == NULL || head -> next -> next == NULL){
            return head ;
        } 
        ListNode* odd = head;
        ListNode* even = head -> next; // 1 -> 2 -> 3 : odd = head = 1 : even  = head -> next = 2 
        ListNode* temp = head -> next -> next; // temp will be 3 : head -> next -> next : 1 -> 2 -> 3 =  3
        ListNode* resEven = head -> next;
        int i = 3;
        while(temp != NULL){
            if( i % 2 != 0){
                // if it is odd node make the next of odd as temp and move the odd pointer 
                odd -> next = temp;
                odd = odd -> next;
            }
            else {
                // if it is even then the next one becomes temp and next moves to right 
                even -> next = temp;
                even = even -> next;
            }
            temp = temp -> next;
            i++;
        }
        // keeping the track of the last odd node 
        odd -> next = resEven;
        even -> next = NULL;

        return head;
    }
};