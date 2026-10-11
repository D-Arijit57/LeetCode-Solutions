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
    bool isSymmetric(TreeNode* root) {
        // we need a queue of pairs
        // the nodes that we are going to compare should be the same
        // for each of the node in the tree
        // their left and right child should have the same value
        // means :
        // node1 -> left == node2 -> right 
        // node1 -> right == node2 -> left

        if(!root) return true;
        queue<pair<TreeNode*, TreeNode*>>pairs;
        // we start from root's left and right child
        pairs.push({root->left, root->right});
        while(!pairs.empty()){
            auto [L, R] = pairs.front();
            pairs.pop();
            // if both dosen't exist then its fine
            if(!L && !R) continue;

            // if one of them exists not both then the tree is not mirror of itself
            else if(!L || !R) return false;

            // if both exists then check their values
            else{
                if(L->val != R->val) return false;
            }

            // push the pairs that are supposed to be compared and 
            // have to be the same leading the tree to be its own mirror
            pairs.push({L->left, R->right});
            pairs.push({L->right, R->left});
        }
    return true;
    }
};