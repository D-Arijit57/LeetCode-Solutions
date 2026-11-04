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
    int preorderdfs(TreeNode* root, int &maxSum){
        // if we have reached the end return
        if(!root) return 0;

        // check the maximum gain from the left subtree and right subtree
        // only the immediate child is not enough since the tree is not a BST
        int leftGain = max(0,preorderdfs(root->left, maxSum));
        int rightGain = max(0,preorderdfs(root->right, maxSum));

        // calculate the maximum path sum between both the subtrees
        // e.g 15 -> 20 -> 7, both of the children are involved, none of them are repeated so it's a valid path
        // e.g 15 -> 20 -> -10 -> 20 -> 7 not a valid path
        int pathSum = root->val + leftGain + rightGain;

        // update the maximum sum
        // since a valid maximum sum path can start and end between any two nodes in the tree
        maxSum = max(pathSum, maxSum);

        // return only the maximum branch between left and right
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        // preorder
        // at each node decide if we need to carry the previous sum or start a new sum 
        int maxSum = INT_MIN;
        preorderdfs(root, maxSum);
        return maxSum;
    }
};