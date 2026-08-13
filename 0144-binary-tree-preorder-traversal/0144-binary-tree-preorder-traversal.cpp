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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        // iterative approach
        vector<int>ans;
        // the stack should only contain the valid nodes
        // the stack represents the set of un-processed nodes
        // more precisely the nodes that we have discovered but we haven't processed yet
        // pre-order traversal :  node -> left -> right
        stack<TreeNode*>st;
        st.push(root);
        // iterate till all of the nodes are processed
        while(!st.empty()){
            TreeNode* curr = st.top();
            // pop when you it the nullptr, previous node was a leaf node
            st.pop();
            ans.push_back(curr->val);
            // since stack is LIFO, we need to -
            // first do push(right) then push(left)
            // because we want the first child to be left and the second one to be right
            // because of the LIFO nature of stack it might reverse it so we push it in reverse manner
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
        }   
        return ans;
    }
};