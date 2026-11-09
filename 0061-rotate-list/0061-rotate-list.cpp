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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode* temp = head;
        int size = 0 ;
        ListNode* tail = nullptr ;
        while(temp){
            size++;
            if(!temp->next) tail = temp;
            temp = temp->next;
        }
        // if k is remainder of size 
        // then rotating it makes no sense as it produces the same linkedlist
        k = k % size; // minimize k
        // as rotation for the same remainder is the same
        // e.g we are going to rotate three times if k is 3, 18 or 27
        if(k == 0) return head;

        // find the node just newTail the first node to rotate
        // size - k
        int pos = size - k;

        

        ListNode* newTail = head;
        ListNode* newHead = head;
        // go till the rotate position
        // newHead is the new head
        while(pos--){
            newTail = newHead;
            newHead = newHead->next;
        }
        
        // assignments
        tail->next = head;
        newTail->next = nullptr;
        return newHead;
    }
};