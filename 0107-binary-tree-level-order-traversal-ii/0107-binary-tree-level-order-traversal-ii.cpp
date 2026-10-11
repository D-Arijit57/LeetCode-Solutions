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
        if(!root) return {};
        queue<TreeNode*>levels;
        levels.push(root);

        vector<vector<int>>ans;
        while(!levels.empty()){
            int levelSize = levels.size();
            
            vector<int>currlevel;
            
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* curr = levels.front();
                levels.pop();

                currlevel.push_back(curr->val);

                if(curr->left) levels.push(curr->left);
                if(curr->right) levels.push(curr->right);
            }
            ans.push_back(currlevel);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};