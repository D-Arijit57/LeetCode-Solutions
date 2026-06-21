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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // incase of head there is no node before 
        // so we are using a dummy node to simplify it
        // it makes sure every node in the list has a node before
        ListNode dummy(0);
        dummy.next = head;
        // we need the node before the nth node from the end
        ListNode* temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        int pos = len - n;
        ListNode* before = &dummy;
        while(pos--){
            before = before->next;
        }
        ListNode* target = before->next;
        // connect before's next to the node after nth node's next
        before->next = target->next;
        target->next = nullptr;
        delete target;
        return dummy.next;
    }
};