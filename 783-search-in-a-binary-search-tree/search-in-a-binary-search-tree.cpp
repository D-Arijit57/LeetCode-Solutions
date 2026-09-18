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
    TreeNode* searchBST(TreeNode* root, int val) {
        // since its a BST one thing we know that 
        // property :  everything in left Subtree < current node < everything in right Subtree
        // if the current node is greater than the val then it cannot exists in the right
        // similarly if its lesser than the val it cannot exists in the left
        // by this navigation strategy we iterate the tree and try to find the val
        // basically we're searching only in the possible spaces instead of everywhere
        if(root == nullptr) return nullptr;
        if(root->val == val) return root;
        if(root->val > val) return searchBST(root->left,val);
        return searchBST(root->right,val);  
    }
};