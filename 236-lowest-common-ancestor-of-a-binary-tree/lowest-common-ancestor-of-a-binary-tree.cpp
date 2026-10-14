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
        if(!root) return nullptr;

        // start from bottom up for p and q 
        // check where they meet at first (their first common point)
        // maintain a parent map 

        // this map stores each node to its immediate parent
        unordered_map<TreeNode*,TreeNode*>parent;
        // root's parent is null
        parent[root] = nullptr;


        queue<TreeNode*>nodes;
        nodes.push(root);

        // using a BFS Traversal
        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            nodes.pop();

            // prepare for the next level
            // while doing so make sure you store the {parent, child}
            // pair in the map as well
            if(curr->left){
                parent[curr->left] = curr;
                nodes.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                nodes.push(curr->right);
            } 
        }
        // now we have the information about all the nodes
        // and their parents

        // We'll traverse upward from p and q using parent pointers
        // then check where they meet at first

        // first pick p and and store all of its ancestors 
        // in a set
        // why set instead of a vector? because it gives us a O(1) look up
        TreeNode* curr = p;
        unordered_set<TreeNode*>ancestors;

        while(curr){
            // as per the definition we are following here
            // the node is a descendant of itself so store it first
            ancestors.insert(curr);
            curr = parent[curr];
        }

        // starting from q check with all p's ancestors
        curr = q;
        while(curr){
            if(ancestors.count(curr)) return curr;
            curr = parent[curr];
        }

        return nullptr;
    }
};