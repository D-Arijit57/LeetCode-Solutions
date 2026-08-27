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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // the queue represents the pair of nodes from the two trees 
        // which are potentially same

        // each of these pair in the queue represents the two nodes from the two different trees
        // which are supposed to be the same 
        queue<pair<TreeNode*, TreeNode*>>same_nodes;
        same_nodes.push({p,q});
        while(!same_nodes.empty()){
            auto [P , Q] = same_nodes.front();
            same_nodes.pop();
            // if both nodes doesn't exist
            if(!P && !Q) continue;
            // if one exists but the other don't exist 
            else if(!P || !Q) return false;
            // if they both exist check the values
            // leffTree's left child == rightTree's left child
            // leftTree's right child == rightTree's right child 
            else {
                if(P->val != Q->val) return false;
            }
            // push the pairs which we are going to compare
            same_nodes.push({P->left,Q->left});
            same_nodes.push({P->right,Q->right});
        }
    return true;
    }
};