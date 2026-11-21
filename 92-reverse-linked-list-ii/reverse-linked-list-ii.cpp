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
        if(!head || !head->next) return head;
        // optimized
        // head insertion **
        // we immediately take the node immediately before the tail and insert it just after beforeLeft
        ListNode dummy(0);
        dummy.next = head;

        ListNode* beforeLeft = &dummy;
        for(int i = 1; i < left ; i++){
            beforeLeft = beforeLeft->next;
        }

        ListNode* curr = beforeLeft->next;
        // this pointer represents / points to the node 
        // that is supposed to reverse and inserted just after BeforeLeft
        // for case 1 : 1 -> 2 -> 3 -> 4 -> 5 it points to 3
        
        int nodesToReverse = right - left;
        while(nodesToReverse--){
            ListNode* nodeToReverse = curr->next;
            // update the curr's next
            curr->next = nodeToReverse->next;
            // update nodeToReverse's next before updating beforeLeft's next
            nodeToReverse->next = beforeLeft->next;
            // connect beforeLeft's next to the just inserted new head of the left boundary
            beforeLeft->next = nodeToReverse;
            
        }
        return dummy.next;
    }
};