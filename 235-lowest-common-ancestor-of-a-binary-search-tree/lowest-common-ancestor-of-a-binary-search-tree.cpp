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
        // edge case : empty tree
        if(root == nullptr) return nullptr;
        // parent_map : represents the record of the each node and their immidate ancestor /parent
        unordered_map<TreeNode*, TreeNode*>parent_map;
        // using a BFS Approach
        queue<TreeNode*>nodes;
        nodes.push(root);
        // initial value of parent_map (root, nullptr)
        parent_map[root] = nullptr;
        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            nodes.pop();
            // iterate every node and store 
            // each node with its immediate parent (ancestor)
            // for both left and right subtree
            if(curr->left){
                parent_map[curr->left] = curr;
                nodes.push(curr->left);
            }
            if(curr->right){
                parent_map[curr->right] = curr;
                nodes.push(curr->right);
            }
        }
        // trace back from p and q
        // record their ancestors
        // the first meeting point becomes the LCA 
        TreeNode* curr = p;
        unordered_set<TreeNode*>ancestors;
        while(curr){
            //  a node can itself be one of the targets for the LCA 
            // the reason why we include p as well
            // otherwise by definition p is not the ancestor of itself
            ancestors.insert(curr);
            // set to curr to the parent of of the current node (we're tracing back)
            curr = parent_map[curr];
           
        }
        
        curr = q;
        while(curr){
           // check if this is the meeting point
           if(ancestors.count(curr)) return curr;
           // if not check the next ancestor using the parent map 
           curr = parent_map[curr];
           
        }
        return nullptr;
    }
};