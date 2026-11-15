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
     pair<TreeNode*, int> postorderdfs(TreeNode* root, pair<TreeNode*, int> &lca){
        // check if you have reach the end
        if(!root) return {nullptr, 0};

        // explore left
        auto leftResult = postorderdfs(root->left, lca);
        // explore right
        auto rightResult = postorderdfs(root->right, lca);

        // if leftSubtree's depth is more than the right
        // the LCA cannot exist in the rightsubtree
        if(leftResult.second > rightResult.second){
            // 1 because we have to count the current node's depth while returning the information to its parent
            // {LCA of deepest leaves must be in the left subtree, 1 + leftsubtree's depth )
            return {leftResult.first, 1 + leftResult.second};
        }

        // similarly if the rightSubtree's depth is more than leftSubtree
        // the LCA cannot exist in the left subtree
        else if(leftResult.second < rightResult.second){


            // 1 because we have to count the current node's depth while returning the information to its parent
            // {LCA of deepest leaves must be in the right subtree, 1 + rightsubtree's depth )
            return {rightResult.first, 1 + rightResult.second};
        }

        // if both's length are the same then the current node is the LCA
        // since the depths are same , take any of them
        else return {root, 1 + leftResult.second};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // use postorder dfs
        // the first node represents the LCA of deepest leaves
        // the integer represents the maxDepth 
        pair<TreeNode*, int>lca = {nullptr, 0};
        return postorderdfs(root, lca).first;
    }
};