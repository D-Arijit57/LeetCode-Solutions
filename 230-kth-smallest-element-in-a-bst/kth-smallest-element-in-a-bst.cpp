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
    void inorderdfs(TreeNode* root, vector<int>&order){
        // if we reach the end of the subtree return
        if(root == nullptr) return;

        // in order traversal

        // process the left subtree
        inorderdfs(root->left, order);

        // process the current node
        order.push_back(root->val);

        // process the right subtree
        inorderdfs(root->right, order);
    }
    int kthSmallest(TreeNode* root, int k) {
        // the BST property says that left < root < right
        // therefore the inorder traversal produce the nodes in ascending order
        // therefore we don't need priority queue
        vector<int>order;
        inorderdfs(root, order);

        int cnt = 0;
        // iterate till kth smallest
        for(auto kth : order){
            cnt++;
            if(cnt == k) return kth;
        }
        return -1;
    }
};