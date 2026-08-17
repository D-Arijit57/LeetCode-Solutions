/**
 * Definition for a binary tree curr.
 * struct Treecurr {
 *     int val;
 *     Treecurr *left;
 *     Treecurr *right;
 *     Treecurr() : val(0), left(nullptr), right(nullptr) {}
 *     Treecurr(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Treecurr(int x, Treecurr *left, Treecurr *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // edge case : empty tree
        if(root == nullptr) return {};
        // postorder sequence : left -> right -> order
        // unlike the inorder or preorder sequence traversal 
        // the stack alone doesn't give us the information if a root's left and right subtree
        // has been completely processed 
        // because of that
        // we would need a stack + extra pointer
        // where stack would represent the ancestors waiting to be processed
        // the extra pointer: prev would represent the subtree we just processed
        // the our framework says that
        // explore a curr's left subtree, once done come back check 
        // prev == curr -> left ? explore right : explore left 
        // then after exploring right if it hasn't been explored
        // check prev == curr ->right ? process curr : explore right
        stack<TreeNode*>st;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        vector<int>ans;
        // till all the currs are processed
        while(!st.empty() || curr){
            // reach the end of the left subtree
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            // once you reach the end of the left subtree
            // go back , [the top of the stack if the ancestor we are returning to]
            curr = st.top();
            // check if the right exists of the ancestor
            // also check if we have already explored its right subtree
            if(curr->right && prev != curr->right){
                curr = curr->right;
            }
            // in-case we have alread explored its left and right subtree
            // now the curr itself can be processed
           else{
                // remember the subtree we just completed 
                prev = curr;

                // add the value to the sequence
                ans.push_back(curr->val);
                // since processed, remove it from the stack
                st.pop();
                
                // since currently there is no subtree right now
                // curr is set to nullptr 
                curr = nullptr;
           }
        }
        return ans;
    }
};