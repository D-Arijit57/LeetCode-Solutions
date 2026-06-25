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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // we can't reverse a single node
        if(k == 1) return head;
        // set a dummy node
        ListNode dummy(0);
        dummy.next = head;

        // set the groupStart and groupEnd (this will help us to set the boundaries)
        ListNode* beforeGroup = &dummy;
        ListNode* groupStart = dummy.next;
        ListNode* groupEnd = dummy.next;

        while(groupStart){
            int actualLen = 0;
            // increase the groupEnd to set the boundary 
            // where the number of nodes between groupStart and groupEnd would be multiple of k 
            while(groupEnd && actualLen < k){
                actualLen++;
                if(actualLen == k) break;
                groupEnd = groupEnd->next;
            }
            // in case groupEnd doesn't exist
            if(actualLen < k) break;
            // set the nextStart
            ListNode* nextStart = groupEnd->next;
            // since we have the range we can reverse the nodes in that range 
            ListNode* curr = groupStart;
            ListNode* prev = nextStart;
            while(actualLen--){
                ListNode* getNext = curr->next;
                curr->next = prev;
                prev = curr;
                curr = getNext;
            }
            // after reversing prev is the new head
            // re-connect the new head with beforeGroup
            beforeGroup->next = prev;
            // set the new before Group as well next groupStart
            beforeGroup = groupStart;
            groupStart = nextStart;
            groupEnd = groupStart;
        }
        return dummy.next;
    }
};