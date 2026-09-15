/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // incase of empty tree
        if(root == nullptr) return nullptr;
        // check if the current node is one of p or q 
        if(root == p || root == q) return root;
        // what makes a node 'curr' the LCA:
        // A node 'curr' is called the LCA of P and Q if P and Q both are contained in the subtree rooted at curr while curr being the point of diversion for the paths of P and Q or curr itself is one of P and Q

        // there two cases :
        // 1. P and Q are in the different subtrees : the common point that connect both of the subtrees becomes the LCA
        // 2. P and Q are in the same subtree : the node placed at the higher level becomes the LCA between P and Q

        // we have to somehow figure out if we are based on the same subtree or different
        // based on that we find the LCA
        // DFS would be a better approach for that because we are traversing to each subtree's depth first

        // At each point of node (root):
        // P and Q both have three options for existence :
        // 1. current node 
        // 2. left subtree
        // 3. right subtree

        // so do we know that a point is LCA :
        // if for a node curr: p is somewhere in the left subtree and q is somewhere in the right subtree
        // or vice versa 
        // or curr == p or curr == q
        // if both p and q are in the left subtree, we know this is not the diversion point so we go more left
        // and same with if they are both happen to be in the right subtree
        TreeNode* curr = root;
        TreeNode* leftResult = lowestCommonAncestor(curr->left,p,q);
        TreeNode* rightResult = lowestCommonAncestor(curr->right,p,q);

        if(leftResult && rightResult){
            return curr;
        }
        if(leftResult){
            return leftResult;
        }
        if(rightResult){
            return rightResult;
        }
        return nullptr;
    }   
};