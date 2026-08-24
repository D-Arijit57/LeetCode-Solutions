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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // normal BFS, reverse at the end
        if(root == nullptr) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>level;
        level.push(root);

        while(!level.empty()){
            int levelSize = level.size();
            TreeNode* curr = level.front();

            vector<int>currLevel;
            for(int i = 0 ; i < levelSize ; i++){
                curr = level.front();
                currLevel.push_back(curr->val);
                level.pop();
                // check if the left and right exists
                // if they do push them
                if(curr->left) level.push(curr->left);
                if (curr->right) level.push(curr->right);
            }
            ans.push_back(currLevel);
        }
        // reverse the list 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};