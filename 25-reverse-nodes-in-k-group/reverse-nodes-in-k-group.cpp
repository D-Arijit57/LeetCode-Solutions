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
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* beforeStart = &dummy;
        // we all the nodes have a node before that helps in reconnection 
        // until we reach the end
        while(beforeStart){
            // the node right next to before becomes the new tail after reversing
            // so we need to remember it, for later reconnection
            ListNode* newStart = beforeStart->next;
            ListNode* groupEnd = beforeStart;
            int actualLen = 0;
            // count the nodes of k group
            while(groupEnd && actualLen < k){
                groupEnd = groupEnd->next;
                actualLen++;
            }
            // if we don't have sufficient nodes then break out of the loop
            // the remaining nodes remain as it is 
            if(groupEnd == nullptr) break;
            ListNode* nextGroup = groupEnd->next;
            // we start reversing after the beforeStart
            ListNode* curr = beforeStart->next;
            ListNode* prev = nextGroup;
            // reverse the group
            while(actualLen--){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // reconnect the beforeStart with the new reversed head
            beforeStart->next = prev;
            // move forward to next group
            beforeStart = newStart;
        }
        return dummy.next;
    }
};