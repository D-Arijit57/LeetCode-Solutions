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
        // use a dummy node so that every node in this list has previous node
        ListNode dummy(0);
        dummy.next = head;
        int original_left = left;
        int original_right = right;
        ListNode* before_left = &dummy;
        ListNode* left_boundary = &dummy;
        // find the left and the pointer just before the left
        while(left_boundary && left--){
            before_left = left_boundary;
            left_boundary = left_boundary->next;
        }
        ListNode* right_boundary = left_boundary;
        // steps we need to move after left to find right 
        int steps = original_right - original_left;
        // find the right boundary and the pointer just after the right
        while(right_boundary && steps--){
            right_boundary = right_boundary->next;
        }
        // find the node just after the right
        ListNode* after_right = right_boundary->next;
        // reverse the segment left to right
        ListNode* prev = right_boundary;
        ListNode* curr = left_boundary;
        // reverse till the cnt
        int reverse_cnt = original_right - original_left + 1;
        while(reverse_cnt--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // connect the new head to the before_left 
        before_left->next = prev;
        // connect the new end with the after_right
        left_boundary->next = after_right;

        return dummy.next;
    }

};