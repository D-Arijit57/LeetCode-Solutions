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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // edge case:
        if(root == nullptr) return {};
        // peform BFS -> level order tarversal
        // once the specific level is done and to be inserted into the answer 
        // just before that reverse if required (if the level is odd)
        queue<TreeNode*>levels;
        levels.push(root);
        vector<vector<int>>ans;
        int levelCnt = 0;
        while(!levels.empty()){
            // freeze the level size
            int levelSize = levels.size();
            
            vector<int>currentLevel;

            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* curr = levels.front();
                levels.pop();

                currentLevel.push_back(curr->val);

                // push the next subtree rooted at the immediate child
                // of the current node's left and right
                // if only they exists
                if(curr->left) levels.push(curr->left);
                if(curr->right) levels.push(curr->right);
            }
            // if the level is odd then only reverse
            // otherwise directly push it
            if(levelCnt % 2 != 0){
                reverse(currentLevel.begin(), currentLevel.end());
                ans.push_back(currentLevel);
            }
            else ans.push_back(currentLevel);
            levelCnt++;
        }
        return ans;
    }
};