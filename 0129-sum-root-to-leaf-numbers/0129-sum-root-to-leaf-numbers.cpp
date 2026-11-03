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
    void preorderdfs(TreeNode* root, int &ans, int currNum){
        // in this case :
        // we don't need to individually remove a digit
        // everytime we move upwards
        // because we aren't meaintaining the reference of currNum
        // 'ans' helps to maintain the previous sum of digits and we just add the current digit if we ever hit the leaf

        // if you reach the end return 
        if(!root) return;

        // if it's a leaf node
        // append the current digit
        currNum = currNum * 10 + (root->val);

        // if it's a leaf (doesn't have any children)
        if(!root->left && !root->right){
            ans += currNum;
            // since it's a leaf 
            // return after processing this node
            return;
        }

        // explore left
        preorderdfs(root->left, ans, currNum);
        // explore right
        preorderdfs(root->right, ans, currNum);

    }
    int sumNumbers(TreeNode* root) {
        // instead of maintaining a string to convert the values of nodes and then add them up
        // we will maintain a integer
        // as for a string it would only work if the digit values are between 0 to 9
        // for values having more than 1 digit 
        // when we use pop_back() while moving upward towards the root after visiting one path
        // it would only remove the last value not the entire digit from the path
        // leading to mis calculation
        // using string will only work here because the constraint of values being 0 to 9 is maintained 
        // since we want to write a optimized, clean and efficient solution that works for every test case out there
        // we would avoid using a string
        
        // edge case: if the tree is empty
        if(!root) return 0;

        int ans = 0,  currNum = 0;
        // preoder dfs
        preorderdfs(root, ans, currNum);
        
        return ans;
        
    }
};