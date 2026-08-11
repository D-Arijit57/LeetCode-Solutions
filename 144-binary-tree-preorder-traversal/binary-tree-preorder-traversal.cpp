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
    vector<int>ans;
    void preOrderDfs(TreeNode* root){
        // if there's no next node return null
        if(root == nullptr) return ;

        TreeNode* node = root;
        // first process the current node
        ans.push_back(node->val);

        // go left
        preOrderDfs(node->left);

        // go right
        preOrderDfs(node->right);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrderDfs(root);
        return ans;
    }
};