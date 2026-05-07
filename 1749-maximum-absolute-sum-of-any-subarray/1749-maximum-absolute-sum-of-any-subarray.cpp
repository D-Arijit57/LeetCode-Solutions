class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0], maxi = nums[0] , currMin = nums[0], mini = nums[0];
        // keep the track of the negatives as well
        for(int i = 1 ; i < n; i++){
            currMax = max(currMax + nums[i], nums[i]);
            maxi = max(currMax, maxi);

            currMin = min(currMin + nums[i], nums[i]);
            mini = min(currMin, mini);
        }
        return max(abs(maxi),abs(mini));
    }
};