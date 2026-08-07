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
    vector<int>ans;
    void inorder_dfs(TreeNode* node){
        // base case :
        // does this node even exist ? if not then stop
        if(node == nullptr) return;

        // process left
        inorder_dfs(node->left);
        
        // process the current node
        ans.push_back(node->val);

        // process right
        inorder_dfs(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // Inorder traversal :  left -> node -> right
        // first explore the left subtree first, then go for the current node then the right
        inorder_dfs(root);
        return ans;
    }
};