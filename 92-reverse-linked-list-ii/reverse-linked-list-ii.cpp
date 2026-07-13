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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // brute force : assign left and right , reverse , connect the ends
        // in reality we don't need right 
        // since we exactly know how many nodes to process for the reversal
        // or you can say have the length of the segment that is supposed to be revsersed
        // edge case
        if(left == right) return head;
        // use a dummy node so that every node in this list has previous node
        ListNode dummy(0);
        dummy.next = head;
        ListNode* before = &dummy;
        for(int i = 1 ; i < left ; i++){
            before = before->next;
        }
        ListNode* leftNode = before->next;

        // reverse the segment left to right
        // process exactly right - left + 1 nodes
        int reverse_cnt = right - left + 1;
        ListNode* curr = leftNode;
        ListNode* prev = nullptr;
        while(reverse_cnt--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // prev is the new head
        // we need to connect the end points right and left
        // connect the new head to the before
        before->next = prev;
        // left_boundary is the tail of the reversed segment
        // or you can say the right end point
        // we need to connect with the node just after 
        // which one should we connect to? its curr
        // curr becomes the node just after the right after the reversal 
        leftNode->next = curr;

        return dummy.next;
    }

};