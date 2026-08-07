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
    vector<int> inorderTraversal(TreeNode* root) {
        // iterative approach
        vector<int>ans;
        // the stack represents the root node of the current subtree we are processing
        stack<TreeNode*>st;
        // we start from the root
        TreeNode* curr = root;
        // while we are not at the end or the stack is not empty
        while(!st.empty() || curr != nullptr){
            // Keep moving left, saving every ancestor.
            // We cannot visit them yet because inorder requires
            // the entire left subtree to be processed first.
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
                }
            // The left subtree has been completely processed.
            // The current node is now the next inorder node.
            curr = st.top();
            st.pop();
            // process the current node
            ans.push_back(curr->val);
            // After visiting the current node,
            // start processing its right subtree
            curr = curr->right;
        }   
        return ans;
     
    }
};