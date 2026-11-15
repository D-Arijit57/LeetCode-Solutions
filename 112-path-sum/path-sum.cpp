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
    bool preorderDfs(TreeNode* root, int &currSum, int targetSum){
        if(!root) return false;

        // process the current node
        currSum += root->val;
        // check if it's a leaf
        if(!root->left && !root->right){
            // if we have found the sum 
            if(currSum == targetSum) return true;
            // if the sum isn't equal then remove the value from the current sum 
            // since we are going back 
            // and return false
            else{
                currSum -= root->val;
                return false;
            }
        }
        // explore left
        bool leftFound = preorderDfs(root->left, currSum, targetSum);
        // explore right
        bool rightFound = preorderDfs(root->right, currSum, targetSum);

        bool found_or_not = leftFound || rightFound;
        // to make sure when we explore a different path 
        // we remove the previous node's value from the currentSum
        currSum -= root->val;
        
        // if we always return false
        // the parent might falsely capture it as the sum being not present even the path is valid
        // so what we do is , we maintain a variable that states
        // if the target is present in one of the subtrees or not
        // so that the parent can keep a track of valid invalid state of sum being present in left or right subtree
        return found_or_not;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // use pre order traversal (dfs)
        int currSum = 0;
        return preorderDfs(root, currSum, targetSum);
    }
};