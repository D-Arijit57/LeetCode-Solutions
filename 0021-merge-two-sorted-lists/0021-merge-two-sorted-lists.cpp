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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        // the dummy node helps to have a situation where every node has a previous node
        // dummy -> [merged_list]
        // Dummy handles the “where does the merged list begin?” problem; tail handles the “where does the next node go?” problem.
        ListNode dummy(0);

        // curr_tail represents the end of the merged list
        ListNode* curr_tail = &dummy;

        // if one list gets empty
        // we got nothing to compare so if anything left
        // then we add the rest of the part to the merged list
        while(list1 && list2){

            // compare the two value
            // reconnect accordingly
            if(list1->val <= list2->val){
               curr_tail->next = list1;
               curr_tail = list1;
               list1 = list1->next;
            }
            // if list2->val is smaller
            else {
                curr_tail->next = list2;
                curr_tail = list2;
                list2 = list2->next;
            } 
        }
        // incase there are any remaining nodes
        // attach them since there is nothing to compare at this point
        if(list1) curr_tail->next = list1;
        if(list2) curr_tail->next = list2;


    return dummy.next;
    }
};