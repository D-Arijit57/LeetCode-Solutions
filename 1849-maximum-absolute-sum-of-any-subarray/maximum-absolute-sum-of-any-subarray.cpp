class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        if(nums.size() == 1) return abs(nums[0]);
        // since the abs(-x) = x 
        // means at each point i we have two choices
        // 1.positive maximum
        // 2.negative minimum 
        // negative minimum can become tomorrow's maximum because
        // we are talking about absolute values
        int n = nums.size();
        int currMin = nums[0], currMax = nums[0];
        int maxSum = nums[0],minSum = nums[0];
        int ans = nums[0];
        for(int i = 1 ; i < n ; i++){
            // update the current max and min
            currMax = max(currMax + nums[i],nums[i]);
            currMin = min(currMin + nums[i], nums[i]);

            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);

            // update the absolute maximum
            ans = max(ans,max(abs(maxSum),abs(minSum)));
        }
        return ans;
    }
};