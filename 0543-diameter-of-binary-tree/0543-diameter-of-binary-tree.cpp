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
    int findPath(TreeNode* root, int &diameter){
        if(root == nullptr) return 0;
        // for each parent to calculate the longest path
        // we need information from both the left and right subtree
        int leftHeight = findPath(root->left, diameter);
        int rightHeight = findPath(root->right, diameter);
        
        // calculate the current node's longest path's length
        int current_length = leftHeight + rightHeight;

        // update the diameter (best seen so far)  
        diameter = max(diameter, current_length);

        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // combine the longest path of left and right subtree
        // dfs approach : post order 
        // since a parent needs information from both of its children
        int diameter = 0;
        findPath(root, diameter);
        return diameter;
    }
};