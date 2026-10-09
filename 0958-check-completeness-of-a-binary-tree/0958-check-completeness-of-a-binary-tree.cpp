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
    bool isCompleteTree(TreeNode* root) {
        // for a binary tree to be identified as complete
        // it has to have filled node levels before the last level
        // means before the last level all the parents can either have 0 or 2 children
        // in the last level each parent can have 0, 1 or 2 children but if the parent has a child it has to be on the left subtree irrespective of the right child

        // we can move forward with a BFS approah
        // the BFS scans the tree from left to right
        // each level needs to have a left subtree either way 
        // why ?
        // if its not the last level it has to be filled, it should have a left child to start with irrespective of the right child
        // if its the last level, irrespective of the right child you need to have a left child for sure, since "all nodes in the last level are as far left as possible"

        if(root == nullptr) return false;

        queue<TreeNode*>levels;
        bool seenNull = false;

        levels.push(root);

        // so logically during BFS. (its top to bottom and left to right)
        // the traversal cannot be 1->2->3->null->4->null
        // it should be 1->2->3->4->5->null->null->null

        while(!levels.empty()){
            TreeNode* curr = levels.front();
            levels.pop();
            
            // we have encountered a missing node
            // now every node from this on has to be missing
            // if there's any node after it the tree becomes invalid as a complete binary tree
            if(curr == nullptr){
                seenNull = true;
            }

            else{
                // We already encountered a gap,
                // but now another node appeared.
                if(seenNull) return false;

                // prepare the nodes for the next level
                // since we have to determine if there's missing node or not
                // we have to push the nulls as well representing the missing node
                levels.push(curr->left);
                levels.push(curr->right);
            }
            
        }

        return true;
    }
};