class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // we keep increasing the window, whenever we meet our target or if the sum is greater than target
        // we shrink the window to find a smaller since our goal is to find the minimal window
        // we need to keep in mind that since we are shrinking a valid one we need to update the answer during the shrinking since we only need a valid window's length
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0, sum = 0;
        for( int right = 0 ; right < n ; right++){
            // expand the window and add the sum
            sum += nums[right];

            // shrink if we have already have the sum or more than that
            // sum >= target, we need to update within this shrinking 
            // because we are shrinking a valid window not a invalid one
            while(sum >= target){
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};