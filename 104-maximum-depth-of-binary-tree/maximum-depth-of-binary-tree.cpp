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
    void postorderDFS(TreeNode* root, int depth, int &ans){
        if (root == nullptr) return ;

        // record the depth only if the current node is a leaf node
        if(!root->left && !root->right) ans = max(ans, depth);

        // explore the left subtree
        postorderDFS(root->left, depth + 1, ans);
        // explore the right subtree
        postorderDFS(root->right, depth + 1, ans);

        // processes the current node
    }
    int maxDepth(TreeNode* root) {
        // egde case : if the input is an empty tree
        /// no need to maintain an array to store the order 
        // since we aren't making any use of it
        if(!root) return 0;

        int depth = 1, ans = INT_MIN;
        postorderDFS(root, depth, ans);
        return ans;
    }
};