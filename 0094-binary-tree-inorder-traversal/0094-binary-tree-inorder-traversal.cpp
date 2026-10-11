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
        // if empty tree return empty array
        if(!root) return {};
        // inorder traversalo : left -> root -> right
        stack<TreeNode*>st;
        TreeNode* curr = root;
        vector<int>ans;
        // if all the nodes haven't processed :
        // either stack is not empty yet or curr is still valid
        while(curr || !st.empty()){
            
            // move left, while there is a left subtree rooted at the immediate left child
            while(curr){
                st.push(curr);
                curr = curr->left;
            }

            // once you reach the end process the current node
            curr = st.top();
            ans.push_back(curr->val);
            // pop() : since we have processed it
            st.pop();
            
            // move to the right 
            curr = curr->right;
            
        }
        return ans;
    }
};