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
    void inorderDFS(TreeNode* root, int &ans, int k, int &cnt){
        if(root == nullptr) return; 

        // go left
        inorderDFS(root->left, ans, k, cnt);

        // process the current node
        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        }

        // go right
        inorderDFS(root->right,ans, k , cnt);

    }
    int kthSmallest(TreeNode* root, int k) {
        // because of the BST property : everything in left subtree  < root < everything in right subtree
        // the inorder of a BST produces strictly increasing sequence of the node values
        vector<int>order;
        int ans = 0, cnt = 0;
        inorderDFS(root, ans, k, cnt);
        return ans;
    }
};