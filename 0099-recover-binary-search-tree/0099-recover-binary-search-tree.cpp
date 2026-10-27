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
    void inorder(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second){
        // if you reach the end of the path return
        if(!root) return;

        // explore left
        inorder(root->left, prev, first, second);

        // everything in the left should have a smaller value compared to the parent
        // if you find a value that is greater
        // assign first and second to the elements which are misplaced
        if(prev && prev->val > root->val){
            
            // if first hasn't been assigned then assign it to the misplaced value
            if(!first){
            first = prev;
            }
            // assign the smaller value to the second (the one which is later in the sequence as per inorder)
            second = root;
        }

        // after moving the next node 
        // update previous
        prev = root;

        // explore right
        inorder(root->right, prev, first, second);
        
    }
    void recoverTree(TreeNode* root) {
       // prev represents the previous node we have explored
       // first : the larger misplaced value
       // second : the misplaced value we find later 
       TreeNode* prev = nullptr;
       TreeNode* first = nullptr;
       TreeNode* second = nullptr;

       // since it's a BST the inorder traversal should produce
       // monotonically increasing sequence of the nodes by their value
       inorder(root, prev, first, second);

       // after the traversal if first and second exists
       // means they have been assigned and there are inversions 
       // swap their value to restore the BST
       if(first && second){
        swap(first->val, second->val);
       } 
    }
};