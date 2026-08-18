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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // edge case : if the tree is empty
        if(root == nullptr) return {};

        // this is BFS traversal problem
        // we are supposed to process the node we discovered at the earliest
        // so we would use a queue because of its FIFO nature
        // At the beginning of each level,
        // the queue contains exactly the nodes belonging to that level.
        // Its size therefore tells us how many nodes we need to process.
        
        // we start with the root
        // we process it, if it has any childrens push them left then right
        // repeat this process until you are done with each and every nodes
        queue<TreeNode*>nodes;
        nodes.push(root);
        vector<vector<int>>ans;
        while(!nodes.empty()){
            // levelSize == queue.size() before processing the level
            int levelSize = nodes.size();

            // since there could be multiple nodes in a level
            // we need another list to store those nodes
            vector<int>currentLevel;

            // Process exactly the nodes that belonged to this level
            // when the level started.
            for(int i = 0 ; i < levelSize; i++){
            // mark the node before popping it out
             TreeNode* curr = nodes.front();
             // process the current node and add them to answer
             currentLevel.push_back(curr->val);
             nodes.pop();

             // if its children (left and right subtree exists) push them
            if(curr->left) nodes.push(curr->left);
            if(curr->right) nodes.push(curr->right);
            }
            ans.push_back(currentLevel);
        }  
        return ans;
    }
};