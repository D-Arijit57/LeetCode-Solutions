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
    bool isFlippedOrNot(TreeNode* L, TreeNode* R){
        // if both of them are not present
         if (!L && !R)
            return true;

        // if only one of them is absent
        if (!L || !R)
            return false;

        // check the value if they are equal
        return L->val == R->val;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // if both of them are absent
        if(!root1 && !root2) return true;
        // if only one of them are absent
        if(!root1 || !root2) return false;
        // stack represents the node that we have discovered but yet to process
        stack<pair<TreeNode*,TreeNode*>>st;
        st.push({root1,root2});
        // until all the nodes gets processed
        while(!st.empty()){
        auto [L,R] = st.top();
        st.pop();  

        // if both nodes doesn't exist
        if(!L && !R) continue;
        // if only one of them exists
        if(!L || !R) return false;
        // if they both exists but don't have the same value
        if(L->val != R->val) return false;
            /*
                At this point we have two possible alignments:
                1. No flip:
                       L->left  <-> R->left
                       L->right <-> R->right
                2. Flip:
                       L->left  <-> R->right
                       L->right <-> R->left
            */
            bool noFlip =
                isFlippedOrNot(L->left, R->left) &&
                isFlippedOrNot(L->right, R->right);
            bool flip =
                isFlippedOrNot(L->left, R->right) &&
                isFlippedOrNot(L->right, R->left);

            if (!noFlip && !flip)
                return false;

            /*
                If both are possible, we cannot simply choose one
                because the deeper structure may invalidate that choice.
                So we preserve both possibilities.
            */
            if (noFlip) {
                st.push({L->left, R->left});
                st.push({L->right, R->right});
            }

            if (flip) {
                st.push({L->left, R->right});
                st.push({L->right, R->left});
            }
        }
    return true;
    }
};