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
    void preorderdfs(TreeNode* root, int &ans, int currNum){
        // if you reach the end return 
        if(!root) return;

        // if it's a leaf node
        // append the current digit
        currNum = currNum * 10 + (root->val);

        // if it's a leaf (doesn't have any children)
        if(!root->left && !root->right){
            ans += currNum;
            // since it's a leaf 
            // return after processing this node
            return;
        }

        // explore left
        preorderdfs(root->left, ans, currNum);
        // explore right
        preorderdfs(root->right, ans, currNum);

    }
    int sumNumbers(TreeNode* root) {
        // edge case: if the tree is empty
        if(!root) return 0;

        int ans = 0,  currNum = 0;
        // preoder dfs
        preorderdfs(root, ans, currNum);
        
        return ans;
        
    }
};