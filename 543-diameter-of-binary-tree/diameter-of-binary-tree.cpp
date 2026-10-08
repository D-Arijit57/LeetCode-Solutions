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
    int findPath(TreeNode* root, int &diameter){
        if(root == nullptr) return 0;
        // for each parent to calculate the longest path
        // we need information from both the left and right subtree
        int leftHeight = findPath(root->left, diameter);
        int rightHeight = findPath(root->right, diameter);
        
        // calculate the current node's longest path's length (edges)

        // why it counts the edges correctly although findPath always returns the height ? 
        // The longest path through the current node uses the deepest
        // path from the left subtree + deepest path from the right subtree.
        // Since heights count nodes, their sum gives the number of edges=
        // in the path through the current node.

        // for example, if there is a path B -> A -> C which goes through A, we are taking the count from B (+1) and C(+1) and the current node A for which we are calculating for gets joined in and doesn't get counted twice
        int current_length = leftHeight + rightHeight;

        // update the diameter (best seen so far)  
        diameter = max(diameter, current_length);

        // The parent can only continue through one child,
        // so return the larger downward height.
        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // combine the longest path of left and right subtree
        // dfs approach : post order 
        // since a parent needs information from both of its children
        int diameter = 0;
        findPath(root, diameter);
        return diameter;
    }
};