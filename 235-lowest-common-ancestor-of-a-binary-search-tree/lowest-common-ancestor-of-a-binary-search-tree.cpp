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
        // since its BST we can determine which subtree to enter
        // we know that p < LCA < q 
        // since its a BST 
        if(root == nullptr) return nullptr;
        TreeNode* curr = root;
        while(curr){
            // if both p and q are smaller than current node
            // then the LCA is probably in the left subtree
            if(p->val < curr->val && curr->val > q->val) curr = curr->left;
            // if both p and q are larger than the current node 
            // then LCA is probably in the right subtree 
            else if(p->val > curr->val && curr->val < q->val) curr = curr->right;
            // the current node would be LCA when
            // P < curr < Q or Q < curr < P
            else return curr ;
        }
        return nullptr;
    }
};