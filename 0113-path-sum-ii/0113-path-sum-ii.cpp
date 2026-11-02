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
    void preorderdfs(TreeNode* root, int targetSum, vector<vector<int>>&ans, int &currSum, vector<int>&currPath) {
        // following a pre order traversal, since we have to process the current node first
        // root->left->right

        // if you reach the end return
        if(!root) return ;

        // add the current value
        currSum += root->val;
        currPath.push_back(root->val);

        // check if it's a leaf
        if (!root->left && !root->right){
            // and it matches the targetSum
            if(currSum == targetSum) {
                // store the answer
                ans.push_back(currPath);
            }
            // if not remove it from the currSum
            // as well as remove it from the currPath as well
            // then return from that node since its a leaf (a dead-end to the current path)
            currSum -= root->val;
            currPath.pop_back();
            return;
        }

        // check whether the path sum exists either in the left or the right subtree
        // from this point on
        preorderdfs(root->left, targetSum, ans, currSum, currPath);
        preorderdfs(root->right, targetSum, ans, currSum, currPath);

        currSum -= root->val;
        currPath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // for every path which's cumulative sum equals to the target sum
        // we need to store the nodes in the same sequence
        // for that we need to maintain a extra stack to keep the trace
        if(!root) return {};
        int currSum = 0;
        vector<int>currPath;
        vector<vector<int>>ans;
        preorderdfs(root, targetSum, ans, currSum, currPath);

        return ans;
    }
};