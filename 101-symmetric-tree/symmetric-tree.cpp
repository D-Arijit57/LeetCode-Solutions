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
        // till level 1 the nodes should be the same
        // after that it follows the pattern: (to be a mirror/ symmetric)
        // leftSubtree->left = rightSubtree->right;
        // leftSubtree->right = rightSubtree->left;
        
        // and empty tree is considered symmetric 
        if(root == nullptr) return true;
        // the queue represents a pair of nodes {l->left, r->right} and {l->right, r->left}
        // these are supposed to be mirrors (should have the same value)
        queue<pair<TreeNode*, TreeNode*>>levels;
        levels.push({root->left, root->right});
        while(!levels.empty()){
            int levelSize = levels.size();

            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* L = levels.front().first;
                TreeNode* R = levels.front().second;
                levels.pop();
                // first check the pair's child's existence
                // e.g if left parent's right child exists but right parent's left child doesn't exist it cannot be a mirror 
                if(!L && !R) continue;

                // if only one of them exists then it cannot be mirror 
                if(!L || !R) return false;

                // if the value isn't the same then it cannot be mirror
                if(L->val != R->val) return false;
                // prepare the next level
                // for the first test case we are storing 
                // {3,3} , {4,4} in the queue
                levels.push({L->left, R->right});
                levels.push({L->right, R->left});
            }
        }
        return true;
    }
};