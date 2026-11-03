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
    void preorderdfs(TreeNode* root, int &ans, string &num){
        // if you reach the end return 
        if(!root) return;

        // if it's a leaf node
        // add up the path 
        num += to_string(root->val);
        if(!root->left && !root->right){
            ans += stoi(num);
            // we have to remove it from the string since it's a leaf 
            num.pop_back();
            // since it's a leaf 
            // return after processing this node
            return;
        }

        // explore left
        preorderdfs(root->left, ans, num);
        // explore right
        preorderdfs(root->right, ans, num);

        // while moving back towards the top
        // remove the last character
        num.pop_back();

    }
    int sumNumbers(TreeNode* root) {
        // edge case: if the tree is empty
        if(!root) return 0;

        int ans = 0;
        string num = "";
        // preoder dfs
        preorderdfs(root, ans, num);
        
        return ans;
        
    }
};