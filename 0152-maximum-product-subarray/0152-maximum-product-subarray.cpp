class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // today's minimum could become tomorrow's maximum
        // since negative * negative = positive 
        // so keep the track of currMin
        // maximum product could be negative as well
        // so we have to consider both the positive and negative scenario
        int n = nums.size();
        int currMax = nums[0], currMin = nums[0];
        int maxProd = nums[0];
        for(int i = 1 ; i < n ; i++){
            // store the current values right now
            // tomorrow it could create the new maximum product
            int oldMax = currMax;
            int oldMin = currMin;

            // updating the new 
            currMax = max({nums[i], oldMax * nums[i], oldMin * nums[i]});
            // we're keeping the track of the minimum
            // since it can contribute to tomorrow's maximum
            currMin = min({nums[i], oldMax * nums[i], oldMin * nums[i]});

            // updating the maximum product
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};