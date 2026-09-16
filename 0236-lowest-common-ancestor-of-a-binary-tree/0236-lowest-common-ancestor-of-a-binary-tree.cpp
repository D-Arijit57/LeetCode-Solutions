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
        // iterative approach 
        // // We build a parent map for every node.
        // Using it, we can trace the ancestor chain of P and Q.
        // the first common ancestor becomes the LCA 
        // as that is the diversion point of P and Q
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;

        // parentmap : e.g parent[5] = 3
        unordered_map<TreeNode*, TreeNode*>parentmap;
        queue<TreeNode*>nodes;
        nodes.push(root);
        parentmap[root] = nullptr;
        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            nodes.pop();
            // push the left and right child
            // while keeping a record of their parents
            if(curr->left){
                nodes.push(curr->left);
                parentmap[curr->left] = curr;
            }
            if(curr->right){
                nodes.push(curr->right);
                parentmap[curr->right] = curr;
            }
        }

       // Store P and all of its ancestors 
       unordered_set<TreeNode*> ancestors;
       TreeNode* curr = p;

       while(curr != nullptr){
        ancestors.insert(curr);
        curr = parentmap[curr];
       }

       // Start from Q and move upward
       // The first node that is also an ancestor of P is the LCA
        curr = q;
        while(curr != nullptr){
            if(ancestors.count(curr)){
                return curr;
            }
            curr = parentmap[curr];
        }

        return nullptr;
    }
};