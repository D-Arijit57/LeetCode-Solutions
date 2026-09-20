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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // edge case : empty list
        if(!head) return nullptr;
        // due to a dummy node every node out there will have a valid node before it
        ListNode dummy(0);
        dummy.next = head;
        int group = 1;
        ListNode* before = &dummy;
        ListNode* groupStart = before->next;
        while(groupStart){
            ListNode* groupEnd = groupStart;
            int actualLen = 1;
            while(groupEnd->next && actualLen < group){
                groupEnd = groupEnd->next;
                actualLen++;
            }
            ListNode* nextGroup = groupEnd->next;
            // check if the length is even, then we can reverse the group
            if(actualLen % 2 == 0) {
                // reverse the group
                ListNode* curr = groupStart;
                ListNode* prev = nextGroup;
                while(actualLen--){
                    ListNode* next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }

                // reconnection
                // prev is the newhead
                before->next = prev;

                // assign new before
                // just before the groupStart
                // since its reversed the groupStart is the new tail
                before = groupStart;
            }
            // if not reversed the groupEnd is the new before
            else  before = groupEnd;
            // set the newGroupStart
            groupStart = nextGroup;
    
            group++;
        }
        return dummy.next;
    }
};