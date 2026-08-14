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
        // inorder traveral :
        // reach the end of the left subtree, comeback process one node, if there is right go right
        // left -> node -> right
        stack<TreeNode*>st;
        TreeNode* node = root;
        vector<int>ans;
        // keep going till there is either a subtree OR there is a ancestor waiting in the stack to be processed
        while(!st.empty() || node != nullptr){
            // while there is a left subtree move left
            // till you reach the end
            while(node != nullptr){
                st.push(node);
                node = node->left;
            }
            // if you reach nullptr means there is no left subtree left
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            // move to the right subtree
            node = node->right;
        }
    return ans;
    }
};