class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algorithm
        // at each index i
        // check if the element nums[i] adds value or else
        // start a new sum
        int n = nums.size();
        int currSum = nums[0];
        int maxSum = nums[0];
        for(int i = 1 ; i < n ; i++){
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(maxSum , currSum);
        }
        return maxSum;
    }
};