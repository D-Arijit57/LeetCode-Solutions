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
    // check if the inorder is strictly increasing
    // as this is a BST 
    // due to its property of left <root< right
    // the inorder traversal will always produce a strictly increasing order
    // instead of storing the order into an array and re check 
    // we can just check it during the runtime of the inorder traversal 
    
    bool inorderDFS(TreeNode* root, TreeNode*& prev){
        if(!root) return true;

        // validate the left subtree
        if(!inorderDFS(root->left,prev)) return false;

        // check if its strictly increasing
        if(prev != nullptr && root->val <= prev->val) return false;

        // Update the previously processed node
        prev = root;

        return inorderDFS(root->right, prev);

    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inorderDFS(root,prev);
    }
};