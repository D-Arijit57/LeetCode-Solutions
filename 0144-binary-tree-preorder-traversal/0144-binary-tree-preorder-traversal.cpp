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
        // the stack represents the nodes that we have discovered but we haven't processed yet
        if(root == nullptr) return {};
        // iterative approach
        vector<int>ans;
        // the top of the stack represents the next un-processed node 
        // pre-order traversal :  node -> left -> right
        stack<TreeNode*>st;
        st.push(root);
        // iterate till all of the nodes are processed
        while(!st.empty()){
            // pop the top of the stack(the unprocessed node)
            // Processing the current node and adding its children to the stack as pending work in an order that causes the stack to produce preorder.
            TreeNode* curr = st.top();
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