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
        if(!head || !head->next || k == 0) return head;
        // if we observe this is not a reversal problem 
        // what we really need to do here is 
        // we need to find a split point, cut the second half, reconnect it to the head 
        // if we observe the position of the new head is : n - k + 1 , new tail : n - k( n: the size of the linkelist )
        ListNode* temp = head;
        int n = 1;
        while(temp->next){
            temp = temp->next;
            n++;
        }
        // make the list circular
        temp->next = head;
        // find the new tail 
        // reduce k (normlization)
        k %= n;
        // if it is n = 7 we need three rotations that's same as n = 3
        // so we normalize it by % N 
        int newHead = n - k + 1;
        int newTail = n - k;
        ListNode* nh = head;
        ListNode* nt = head;
        // find the newtail
        for(int i = 1 ; i < newTail ; i++){
            nt = nt->next;
        }
        // find the new head
        for(int i = 1; i < newHead ; i++){
            nh = nh->next;
        }
        nt->next = nullptr;
        return nh;
    }
};