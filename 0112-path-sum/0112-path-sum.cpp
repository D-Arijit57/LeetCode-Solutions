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
    bool inorderDFS(TreeNode* root, int targetSum, int &currSum){
        // currSum : it represents the sum of values along the path from the original root to the current node, including the current node.

        if(!root) return false;
        // process node
        // add its value to the same
        currSum += root->val;

        // if you reach the end
        // check the path sum with the targetsum
        // if a node is leaf then it shouldn't have left and right children
        if(!root->left && !root->right){
            // if the sum is equal
            if(targetSum == currSum) return true;

            // if the sum is not equal
            // then we explore a different but 
            // getting back from this leaf
            // so subtract this leaf's value
            // and return false
            currSum -= root->val;
            return false;
        }

       // the sum can exist in either of the subtrees
       // so we cannot just discard the result here
       // go left
       bool left = inorderDFS(root->left, targetSum, currSum);
       // go right
       bool right = inorderDFS(root->right, targetSum, currSum);

       // check if you have found the targetSum in either of the subtree's path
       bool found = left || right;

    /*
    - So why restore currSum?

        Because the recursive function has two responsibilities:

    1. Return whether a valid path exists.
    2. Restore the state it received so its caller isn’t left with modified data.
    */
       currSum -= root->val;
       return found;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // we can use a dfs solution for this (preorder, since we have calculate the currSum with the nodes value)
        // so process the curr node first
        // for each root-to-leaf path
        // when we hit the leaf node
        // we would compare the targetsum with the current
        // if it's not the same then we check a different path 
        // we have make sure we subtract the value of the leaf we just came back from
        int currSum = 0;
        return inorderDFS(root, targetSum, currSum);
    }
};