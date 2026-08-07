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
    void inorder_dfs(TreeNode* node, vector<int>&ans){
        // base case : if the node doesn't exist at all then stop exploration
        if(node == nullptr) return ;

        // inorder traversal:
        // explore left till you reach end of the left subtree
        inorder_dfs(node->left,ans);

        // process the current node
        ans.push_back(node->val);

        // since we already explore left, and the current node as well
        // explore the right subtree till you reach the end of the right subtree
        inorder_dfs(node->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // recursive approach
        vector<int> ans;
        inorder_dfs(root, ans);
        return ans;
    }
};