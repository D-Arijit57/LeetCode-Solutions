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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        // invert :
        // for each parent its left subtree becomes right and right subtree becomes left
        // traverse using bfs and swap the subtrees for each node
        queue<TreeNode*>level;
        level.push(root);
        while(!level.empty()) {
            int levelSize = level.size();
            
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* curr = level.front();
                level.pop();

               // swap the left and right subtree
               TreeNode* temp;
               temp = curr->right;
               curr->right = curr->left;
               curr->left = temp;

               // prepare the next level
               if(curr->left) level.push(curr->left);
               if(curr->right) level.push(curr->right);

            }
        }
        return root;
    }
};