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
        // post order dfs :
        // left -> right -> root
        if (root == nullptr) return;

        // if the node is leaf
        // the only record the depeth
        if(!root->left && !root->right) ans = min(ans, depth);
        
        // explore the left subtree
        postorderDFS(root->left, depth + 1, ans);
        // explore the right subtree
        postorderDFS(root->right, depth + 1, ans);

        // processes current node
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        // going for a DFS approach : Post order traversal
        // for each of the node check if it has left or right children
        // if they do explore till the leaf node then and update the depth
        // if the current node is leafNode then record the depth
        // intial depth is 1
        int depth = 1, ans = INT_MAX;
        postorderDFS(root, depth, ans);
        return ans;
    }
};