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
        if(root == nullptr) return {};
        // we have altenate squence left->right, right-> left at alternate levels
        // starting from level 0 (l -> r), the level 1 (r -> l) and so on 
        // if you notice all even levels sequence are left -> right
        // and right -> left for all the odd levels
        // keep in mind that the sequence is not an node discovery concern
        // its an output concern so we can reverse that before pushing if the level is odd or even accordingly
        vector<vector<int>>ans;
        queue<TreeNode*>levels;
        levels.push(root);
        int levelCnt = 0;
        // until all the levels are processed completely
        while(!levels.empty()){
            int levelSize = levels.size();
            vector<int>currLevel;
            // process the current level completely
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* curr = levels.front();
                currLevel.push_back(curr->val);
                levels.pop();

                // check if the nodes have children if they have push them left -> right
                if(curr->left) levels.push(curr->left);
                if(curr->right) levels.push(curr->right);
            }
            // if its odd level the sequence of nodes is supposed to be right to left
            if(levelCnt % 2 == 1){
                reverse(currLevel.begin(), currLevel.end());
                ans.push_back(currLevel);
            }
            // if its even then left to right
            else{
                ans.push_back(currLevel);
            }
            // increase the level count once a level is completely processed 
            levelCnt++;
        }
        return ans;
    }
};