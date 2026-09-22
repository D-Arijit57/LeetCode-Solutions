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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // edge case : if the tree is empty
        if(root == nullptr) return nullptr;
        
        // we are trying solve children of every parent node 
        // and get the required informaton that is (depth,LCA)
        // the parent node process this information and checks -
        // 1. if left subtree depth > right subtree depth the LCA for sure exists somewhere in the left subtree
        // 2. if the right subtree depth > left subtree depth the LCA for sure exists somewhere in the right subtree 
        // 3. if the depth of the both subtrees are the same for the current node 
        // the current node is the LCA
        // using a post order traversal 

        // we store the information of the node and if its visited or not 
        // visited = True : we have processed its children now process this node
        // visited = False : childrens are yet to process
        stack<pair<TreeNode*,bool>>st;
        st.push({root,false});

        // each child would produce something like (depth, LCA)
        // so we would need something to store it
        // e.g. result[2] = {4,2}, the subtree rooted at 2 has a depth of 4 and the LCA is 2
        unordered_map<TreeNode*,pair<int,TreeNode*>>result;
        while(!st.empty()){
            auto[curr, visited] = st.top();
            st.pop();

            // if the children are not processed 
            if(visited == false){
                // we need to process the children first
                st.push({curr, true});

                // push the right first since during popping the sequence is reversed
                if(curr->right) st.push({curr->right, false});
                if(curr->left) st.push({curr->left,false});
            }

            // if the children are already processed
            else {
                // Since a child might not exist the depth should be -1 initially
                int leftDepth = -1;
                int rightDepth = -1;

                TreeNode* leftLCA = nullptr;
                TreeNode* rightLCA = nullptr;

                // if left exists store the depth
                // and the LCA
                if(curr->left){
                    leftDepth = result[curr->left].first;
                    leftLCA = result[curr->left].second;
                }

                // if right exists store the depth
                // and the LCA
                if(curr->right){
                    rightDepth = result[curr->right].first;
                    rightLCA = result[curr->right].second;
                }

                // if left subtree > right subtree then for sure the LCA exists somewhere in the left subtree
                if(leftDepth > rightDepth){
                    result[curr] = {leftDepth + 1, leftLCA};
                }
                // if left subtree < right subtree then for sure the LCA exists somewhere in the right subtree
                else if(leftDepth < rightDepth){
                    result[curr] = {rightDepth + 1, rightLCA};
                }
                // if the left subtree == right subtree then the current node is the LCA
                else result[curr] = {leftDepth + 1, curr};
            }
        }
        return result[root].second;
    }
};