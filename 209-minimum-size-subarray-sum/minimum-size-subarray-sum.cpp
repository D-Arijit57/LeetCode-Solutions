class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int minLen = INT_MAX;
        int left = 0;
        for(int right = 0 ; right < n ; right++){
            // add new elements and increase the sum
            sum += nums[right];

            // if the sum is already greater than or equal to the target
            // we'll try to find a subarray where the length is lesser 
            while(sum >= target){
                // update first since this is a valid subarray 
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen ;
    }
};