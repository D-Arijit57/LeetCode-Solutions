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
    bool findTarget(TreeNode* root, int k) {
        // Optimized solution:

        // if you conceptually think the tree as a flattened array
        // it would be something like 2,3,4,5,6,7
        // since the its binary search ree and its sorted

        // two pointer approach :
        // since we know this is a BST 
        // everything in leftsubtree < curr < everything in rightsubtree
        // so we would have two pointers in each of its two subtrees
        // one pointing (L) to the smaller ones in the left and one pointing (R) to the larger one in the right
        // because of invariant L <= R always
        if(root == nullptr) return false;
        stack<TreeNode*> leftStack;
        stack<TreeNode*> rightStack;

        TreeNode* curr = root;

        // Initialize the left iterator to the smallest node
        while(curr){
            leftStack.push(curr);
            curr = curr->left;
        }
        // Initialize right iterator to the largest node

        curr = root;
        while (curr) {
            rightStack.push(curr);
            curr = curr->right;
        }
        // one of them runs out first
        while(!leftStack.empty() || !rightStack.empty()){
            TreeNode* leftNode = leftStack.top();
            TreeNode* rightNode = rightStack.top();

            if(leftNode == rightNode) break;

            int sum = leftNode->val + rightNode->val;

            if(sum == k) return true;

            // if the sum is smaller than target
            // Move to next larger value
            else if(sum < k){
                leftStack.pop();

                curr = leftNode->right;
                while(curr){
                    leftStack.push(curr);
                    curr = curr->left;
                }
            }

            // if sum is greater then move the pointer that is pointing to the larger element
            else {
            // Move to next smaller value
                rightStack.pop();

                curr = rightNode->left;
                while (curr) {
                    rightStack.push(curr);
                    curr = curr->right;
                }
            }

        }
        return false;
    }
};