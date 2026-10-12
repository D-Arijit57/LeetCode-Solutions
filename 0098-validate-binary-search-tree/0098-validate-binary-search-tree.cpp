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
    void inorderDFS(TreeNode* root, vector<int>&order){
        // brute force approach
        // if we have reached the end return
        if(root == nullptr) return;

        // explore left subtree
        inorderDFS(root->left, order);

        // process the current node
        order.push_back(root->val);

        // explore right subtree
        inorderDFS(root->right, order);
    }
    bool isValidBST(TreeNode* root) {
        // considering the binary tree to be a BST
        // its inorder should produce strictly increasing order
        // we can just store that order and check
        vector<int>order;
        inorderDFS(root, order);

        // check if its strictly increasing
        int n = order.size();
        for(int i = 1 ; i < n ; i++){
            // if at any point it breaks the strictly non-decreasing order
            // the given tree is not a BST
            if(order[i] <= order[i-1]) return false;
        }

        // if the order (strictly increasing is maintained)
        // its a BST
        return true;
    }
};