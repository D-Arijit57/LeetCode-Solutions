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
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        queue<pair<TreeNode*,TreeNode*>>pairs;
        pairs.push({root,subRoot});
        while(!pairs.empty()){
            auto [L,R] = pairs.front();
            pairs.pop();
            // if both node doesn't exist, we can continue
            // since its still the same tree
            if(!L && !R) continue;
            // if only one of them exists
            if(!L || !R) return false;
            // if both of them exists then check the value 
            if(L->val != R->val) return false;
            pairs.push({L->left,R->left});
            pairs.push({L->right, R->right});
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // find out the candidate subRoot (as there could be multiple), for every candidate check its entire subTree with the given subRoot

        // edge case : if one of them is empty
        if(root == nullptr && subRoot) return false;

        // for every candidate node 
        // check the entire tree with subRoot to see if the matches entirely
        TreeNode* currSubRoot = subRoot;
        queue<TreeNode*>nodes;
        nodes.push(root);
        // check if the subRoot exists in the main tree
        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            if(curr->val == currSubRoot->val){
               // compare if this node has the same subtree as subRoot
               // same tree logic : use a helper function to keep the code clean
               // pass both of the nodes as the root and check the mirroring node values
               // root->left, subRoot->left and root->right, subRoot->right
               if (isSameTree(curr, currSubRoot)) return true;
            } 
            nodes.pop();
            if(curr->left) nodes.push(curr->left);
            if(curr->right) nodes.push(curr->right);
        }
        return false;
    }
};