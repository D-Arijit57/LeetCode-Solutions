/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        while(curr){
            // if its the same value then return immediately
            if(curr->val == val) return curr;
            // if the current node is smaller than the target
            // there's no way it can exist on the left side
            if(curr->val < val) curr = curr->right;
            // if the current node is greater than the target
            // for sure the value exists in the left
            else curr = curr->left;
        }
        return nullptr;
    }
};