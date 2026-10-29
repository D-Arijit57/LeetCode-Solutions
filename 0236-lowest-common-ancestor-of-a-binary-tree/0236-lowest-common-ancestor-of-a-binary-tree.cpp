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
        if(!root) return nullptr;

        // maintain a parent map
        // where we store the current node and its immediate ancestor
        // e.g for the root since there is no ancestor (no parent) we store nullptr
        unordered_map<TreeNode*, TreeNode*>parent;

        parent[root] = nullptr;

        queue<TreeNode*>nodes;
        nodes.push(root);

        // traverse the tree (using BFS here)
        // and store all the parent child relationships in the parent map
        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            nodes.pop();

            // if subtree exists (left / right)
            // before pushing it into the queue for the next iteration
            // make sure you store the relationship 
            // e.g left subtree's parent is the current node moving forward
            if(curr->left){
                parent[curr->left] = curr;
                nodes.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                nodes.push(curr->right);
            }
        }

        // starting from p and q
        // check for the first meeting point going upwards using the parent map 
        TreeNode* curr = p;
        // using a set 
        // since using a vector would result in a O(N) search requirement at the worse case
        // set provides us a O(1) constant look up
        unordered_set<TreeNode*>ancestors;
        while(curr){
            // since by definition that we are following here
            // a node is a descendant of itself
            // before going upward we need to store it as a descendant of itself here 
            ancestors.insert(curr);
            curr = parent[curr];
        }

        // starting from queue while moving upward 
        // check with p using the ancestors (set) 
        // if they have any common ancestor
        // as that is the first meeting point 
        curr = q;
        while(curr){
            if(ancestors.count(curr)) return curr;
            curr = parent[curr];
        }

        return nullptr;
    }
};