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
    bool findTarget(TreeNode* root, int k) {
        // optimized solution
        // keep an record of the pair (required) that we have encountered in a set
        // if a the required exists it'll fulfill the condition of its other half
        if(root == nullptr) return false;
        
        // using stack for DFS
        stack<TreeNode*>st;
        st.push(root);

        // hash set contains values whose complementary partner we're still looking for 
        unordered_set<int>seen;

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            int required = k - curr->val;
            // if the other half already exists then return directly
            if(seen.count(required)) return true;
            // other wise record if in case we encounter its complement in future
            seen.insert(curr->val);

            // pre order DFS
            if(curr->left)  st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }
        return false;
    }
};