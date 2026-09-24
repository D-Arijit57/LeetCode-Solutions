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
    bool findTarget(TreeNode* root, int k) {
        // everything in leftsubtree < current node < everything in right subtree
        // so at each point we can decide whether go left or right
        // at current node we are going calculate the required half i.e target - curr->val
        // and we are going to check based on if that required value is greater than the current node or not
        if(root == nullptr) return false;
        queue<TreeNode*>levels;
        levels.push(root);
        // check for each of the node 
        while(!levels.empty()){
            TreeNode* curr = levels.front();
            levels.pop();
            int required = k - curr->val;

            // current candidate starts from the root
            // uses BST Property to check whether the required exists in the subtree or not 
            TreeNode* candidate = root;

            while(candidate){ 
            // make sure we don't return based on just the value 
            // but we have to re check if we have another unique node by comparing their respective addresses
            if(required == candidate->val &&  candidate != curr){
                return true;
            }
            // if the required value is greater than the current node's value then it probably exists in the right subtree
            if(required > candidate->val) candidate = candidate->right;
            // if its smaller then it probably exists in the left subtree
            else candidate = candidate->left;
            }

            // push the next left and right subtrees
            if(curr->left){
                levels.push(curr->left);
            }
            if(curr->right){
                levels.push(curr->right);
            }
        }
        return false;
    }
};