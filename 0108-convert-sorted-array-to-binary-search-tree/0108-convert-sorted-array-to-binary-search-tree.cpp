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
    TreeNode* buildBST(vector<int>&nums, int left, int right){
        // since the array is sorted
        // if we find a middle point within the given range
        // every element in the right will be larger than it 
        // and every element in the left will be smaller than it
        if(left > right) return nullptr;

        // find the middle
        int middle = left + (right - left) / 2;

        // assign it as the root node
        TreeNode* root = new TreeNode(nums[middle]);

        // build the left subtree
        root->left = buildBST(nums, left, middle - 1);
        // build the right subtree
        root->right = buildBST(nums, middle + 1, right);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // find the element that divides the array into two sorted halves
        // choose that as a root
        // all the elements in the left and the right becomes it's left and right subtree
        int n = nums.size();
        int left = 0, right = n - 1;
        return buildBST(nums, left, right);
    }
};