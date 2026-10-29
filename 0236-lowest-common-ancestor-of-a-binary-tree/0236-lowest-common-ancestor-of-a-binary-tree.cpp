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

        unordered_map<TreeNode*, TreeNode*>parent;

        parent[root] = nullptr;

        queue<TreeNode*>nodes;
        nodes.push(root);

        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            nodes.pop();

            if(curr->left){
                parent[curr->left] = curr;
                nodes.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                nodes.push(curr->right);
            }
        }

        TreeNode* curr = p;
        unordered_set<TreeNode*>ancestors;
        while(curr){
            ancestors.insert(curr);
            curr = parent[curr];
        }

        curr = q;
        while(curr){
            if(ancestors.count(curr)) return curr;
            curr = parent[curr];
        }
        return nullptr;
    }
};