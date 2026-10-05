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
    int height(TreeNode* root){
        // empty tree : height is 0 
        if(!root) return 0;

        // calculate the leftHeight
        int leftHeight = height(root->left);
        // if its the initial root the height is initally -1
        if(leftHeight == -1) return -1;

        // calculate the rightHeight
        int rightHeight = height(root->right);
        // if its the initial root the height is initally -1
        if(rightHeight == -1) return -1;


        // check the difference
        // if its greater than 1 
        if(abs(leftHeight - rightHeight) > 1) return -1;

        // other wise 
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        // main condition that we have to check for every node in the tree
        // abs (height of the left subtree - height of the right subtree)  <= 1
        // height = maximum number of edges on a path from root to any leaf node
        return height(root) != -1;
    }
};