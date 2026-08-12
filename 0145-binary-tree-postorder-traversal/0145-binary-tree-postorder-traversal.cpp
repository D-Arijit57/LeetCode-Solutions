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
    void postOrderDfs(TreeNode *root, vector<int>&ans){
        if(root == nullptr) return;
        TreeNode* node = root;
        // move left
        postOrderDfs(node->left, ans);

        //move right
        postOrderDfs(node->right,ans);

        //store the node
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postOrderDfs(root,ans);
        return ans;
    }
};