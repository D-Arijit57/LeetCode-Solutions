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
    void preorderdfs(TreeNode* root, vector<vector<int>>&paths, vector<int>&currPath, int &currSum, int targetSum){
        if(!root) return;

        currSum += root->val;
        currPath.push_back(root->val);

        if(!root->left && !root->right){
            if(currSum == targetSum){
                paths.push_back(currPath);
                // mistake : forgot to save the state 
                // by removing the current node's value
                // and pop_back() from currPath
                currSum -= root->val;
                currPath.pop_back();
                return;
            }
            else{
                currSum -= root->val;
                currPath.pop_back();
                return;
            }
        }

        preorderdfs(root->left, paths, currPath, currSum, targetSum);
        preorderdfs(root->right, paths, currPath, currSum, targetSum);

        currSum -= root->val;
        currPath.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>paths;
        int currSum = 0; vector<int>currPath;
        preorderdfs(root, paths, currPath, currSum, targetSum);
        return paths;
    }
};