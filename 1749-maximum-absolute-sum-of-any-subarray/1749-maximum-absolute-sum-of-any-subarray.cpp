class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Kadane's Algorithm 
        // At each index i check :
        // if we can extend the previous subarray
        // or should we start a new one 
        // since if the sum is negative then there's no point of extendng the current subarray 

        int n = nums.size();
        int currMaxSum = nums[0];
        int maxSum = nums[0];
        int currMinSum = nums[0];
        int minSum = nums[0];
        int maximum_sum = INT_MIN;
        for(int i = 1; i < n ; i++){
           currMaxSum = max(nums[i] , currMaxSum + nums[i]);
           maxSum = max(currMaxSum,maxSum);

           currMinSum = min(nums[i], currMinSum + nums[i]);
           minSum = min(currMinSum , minSum); 

        }
        maximum_sum = max(abs(maxSum),abs(minSum));
        return maximum_sum;
    }
};