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
    int kthSmallest(TreeNode* root, int k) {
        // the first thing we can think of is a basic BFS + min heap
        // the min heap always stores the smallest in the current sequence
        // so after storing all of the node inside the queue
        // we can just pop it up k times to find the kth smallest element
        priority_queue<int, vector<int>, greater<int>>min_heap;
        queue<TreeNode*>nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            nodes.pop();

            // push the value into the min_heap
            min_heap.push(curr->val);
            
            // if it exists ; push the left subtree rooted at the immdidate left child
            if(curr->left) nodes.push(curr->left);
            // if it exists ; push the right subtree rooted at the immdidate right child
            if(curr->right) nodes.push(curr->right);
        }

        // pop the min_heap k times to find the kth smallest element
        for(int i = 1 ; i < k ; i++){
            min_heap.pop();
        }

        // after popping exactly k times
        // return the top of the min heap
        return min_heap.top();
    }
};