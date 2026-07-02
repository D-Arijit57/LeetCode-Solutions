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
    ListNode* removeNodes(ListNode* head) {
        // if there's only one node return the head
         if(!head->next) return head;
        // The stack maintains a decreasing sequence of surviving node values for the processed prefix
        // which have a greater element anywhere to its right
        stack<ListNode*>nodeval;
        ListNode* temp = head;
        while(temp){
            // each incoming element can cancel more than one element 
            // so we need a while loop for checking the condition
            // while the current element is greater than the top
            // remove elements till the top becomes greater the than current one
            // else push the current element
            while(!nodeval.empty() && nodeval.top()-> val < temp->val){
                nodeval.pop();
            }
            // push the current one into the stack
            nodeval.push(temp);
            temp = temp->next;
        }
        // re-build the linkedlist
        ListNode* prev_node = nullptr;
        while(!nodeval.empty()){
            ListNode* node = nodeval.top();
            nodeval.pop();
            node->next = prev_node;
            prev_node = node;
        }
        // the new head 
        return prev_node;

    }
};