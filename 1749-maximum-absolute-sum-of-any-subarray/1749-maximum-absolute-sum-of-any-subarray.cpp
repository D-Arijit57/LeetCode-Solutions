class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int currMax = nums[0];
        int minSum =  nums[0];
        int currMin = nums[0];
        int maximum_abs_sum = INT_MIN;
        for(int i = 1 ; i < n ; i++){
            // for each index i :
            // either extend the prev subarray if the current sum is greater 
            // or start a new one since there is no point of adding a element if its reduces the sum 
            // we calculate it for both the maximum and minimum since we are finding absolute sum
            // the maximum could be negative 
            // for example : maximumAbs = max(abs(3) , abs(-8)) = 8
            currMax = max(nums[i],currMax + nums[i]);
            maxSum = max(maxSum ,currMax);

            currMin = min(nums[i],currMin + nums[i]);
            minSum = min(minSum ,currMin);
        }
        maximum_abs_sum = max(abs(maxSum) , abs(minSum));
        return maximum_abs_sum;
    }
};