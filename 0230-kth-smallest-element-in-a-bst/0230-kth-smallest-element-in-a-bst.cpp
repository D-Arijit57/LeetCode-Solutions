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
        if(root == nullptr) return; 

        // go left
        inorderDFS(root->left, order);

        // process the current node
        order.push_back(root->val);

        // go right
        inorderDFS(root->right, order);

    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>order;
        inorderDFS(root, order);


        // since the order is strictly increasing
        // starting from position
        // tarverse till kth position
        // you'll have the kth largest element
        int ans = 0;
        for(int i = 0 ; i < k ; i++){
            ans = order[i];
        }
        return ans;
    }
};