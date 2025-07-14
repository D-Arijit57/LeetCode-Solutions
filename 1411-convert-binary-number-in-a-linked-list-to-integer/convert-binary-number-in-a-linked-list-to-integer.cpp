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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        
        // Traverse the linked list
        while (head != nullptr) {
            // Shift result left by 1 bit and add current node's value
            result = (result << 1) + head->val;
            head = head->next;
        }
        
        return result;
    }
};

// Alternative approach using multiplication (equivalent to bit shifting)
class Solution_Alt {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        
        while (head != nullptr) {
            // Multiply by 2 and add current digit
            result = result * 2 + head->val;
            head = head->next;
        }
        
        return result;
    }
};