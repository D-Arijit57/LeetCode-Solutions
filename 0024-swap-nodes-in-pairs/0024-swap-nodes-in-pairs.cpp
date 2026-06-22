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
    ListNode* swapPairs(ListNode* head) {
        // in case the list is empty or there is only one element return it
        if(!head || !head->next) return head;

        // the dummy nodes makes sure every node in the list has a node before
        // simplifying it so that can place our prev/before pointer before the head
        ListNode dummy(0);
        dummy.next = head;

        ListNode* before = &dummy;
        ListNode* p1 = before->next;
        ListNode* p2 = p1->next;
        
        // swap pairs till p1 and p2 exists
        while(p1 && p2){
            // precompute the nexts before swapping to move forward 
            // after swapping before should p1 
            // or else this is how would look like
            // structure before swapping : before->p1->p2
            // structure after swapping : before->p2->p1
            ListNode* nextBefore = p1;
            ListNode* nextP1 = p2->next;

            // swap the pair
            before->next = p2;
            p1->next = p2->next;
            p2->next = p1;

            //after swapping move forward
            before = nextBefore;
            p1 = nextP1;
            // if p1 exists then only p1->next othewise if p1 is already at nullptr
            // the p1->next would cause a crash
            p2 = p1 ? p1->next : nullptr;
        }
        return dummy.next;
    }
};