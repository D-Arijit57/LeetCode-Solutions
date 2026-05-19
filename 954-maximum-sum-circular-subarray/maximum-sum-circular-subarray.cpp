class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // either,
        // 1. the normal subarray has the maximum sum
        // 2. or the wrap around has the maximum sum , in that case total - minsum  
        int currMax = 0, currMin = 0;
        int maxSum = nums[0], minSum = nums[0];
        int total = 0;

        for(int x : nums){
            currMax = max(x , currMax + x);
            currMin = min(x, currMin + x);

            maxSum = max(maxSum, currMax);
            // to track the minimum 
            minSum = min(minSum, currMin);

            total += x;
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};