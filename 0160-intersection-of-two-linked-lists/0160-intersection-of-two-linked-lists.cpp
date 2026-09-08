/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // intersection : not the same value of two nodes
        // it means the two nodes point to the same location in memory
        // Each pointer traverses both lists once. The redirection cancels out the difference in their lengths, so if an intersection exists, both pointers reach the shared node at the same time.
        ListNode* list1 = headA;
        ListNode* list2 = headB;

        // fast and slow pointer approach
        while(list1 || list2){
            if(list1 == list2) return list1;
            // compare one list's node with every node of the other list
            // if one reaches the the end redirect it to the head of the list
            list1 = list1 ? list1->next : headB;
            // why check list1 instead of list1->next?
            // because we have to check is current list1 is valid or not 
            // if its already a nullptr it makes no sense to do list->next
            list2 = list2 ? list2->next : headA;   
        }
        return nullptr;
    }
};