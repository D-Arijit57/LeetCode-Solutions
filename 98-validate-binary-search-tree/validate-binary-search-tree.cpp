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
    // custom struct for storing current node, lower and upper bound
    struct nodeInfo{
        TreeNode* node;
        long long lower;
        long long upper;
    };
    bool isValidBST(TreeNode* root) {
        // note : this approach fails for [5,4,6,null,null,3,7], because the for the childs 3,7 they are compared with 6 only (locally) not with the root (5) , if you check them locally it would be correct as 3 is on left of 6 and 7 is at the right of 3. 
        // but at a global level this is wrong
        // its the fundamental limitation in this algorithm
        // A BST is not defined by the relationship between each parent and its immediate children. It’s defined by the relationship between each node and every value in its left and right subtrees.

        //**** because of this we have to maintain valid bounds
        // best we have seen in the left and the right

        // BFS with Bounds



    // we can come up with a BFS Approach to check if at every node 
    // left subtree < root < right subtree
    // an empty tree is a valid tree
    if(root == nullptr) return true;
    // check for the root explicitly
    // at root
    // it should be leftchild < root < rightchild
    if(root->left){
        if(root->left->val > root->val) return false;
    }
    if(root->right){
        if(root->right->val < root->val) return false;
    }

    // For the BFS approach, each entry contains:
    // 1. The current node we need to validate.
    // 2. The valid range (lowerBound, upperBound) within which that node’s value must lie.

    queue<nodeInfo>nodes;
    // -infinity, + infinity for lower and upper bound at root
    nodes.push({root,LLONG_MIN,LLONG_MAX});
    
    while(!nodes.empty()){
        nodeInfo curr = nodes.front();
        nodes.pop();
    
        // check if the current node is in the valid boundary
        // checks if there is any anomaly at a global level
        if (curr.node->val <= curr.lower || curr.node->val >= curr.upper) {
        return false;
        }

        // at each node check 
        // if the core property of the binary search tree is maintained

        // if only the left child exists
        // then check if the left child is smaller or not (as it should be)
        if(curr.node->left) {
            if(curr.node->left->val >= curr.node->val) return false;
            nodes.push({curr.node->left, curr.lower, curr.node->val});
        }

        // if only the right child exists 
        // then check if the value is greater or not (as it should be)
        if(curr.node->right) {
            if(curr.node->right->val <= curr.node->val) return false;
            nodes.push({curr.node->right, curr.node->val, curr.upper});
        }

    }
    return true;
    }
};