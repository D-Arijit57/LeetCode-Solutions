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
            // go till the end of the left subtree
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
                }
            // the left subtree is processed
            curr = st.top();
            st.pop();
            // process the current node
            ans.push_back(curr->val);
            // go for the right since left is already being processed
            curr = curr->right;
        }   
        return ans;
     
    }
};