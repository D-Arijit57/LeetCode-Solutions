class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // We will be using a sliding window approach
        // for each new element we would add it up to the sum 
        // if sum >= target we update the minLen
        // since we already got a answer and want to find another one with minimum length
        // we would shrink the window and try to find a new one 
        int n = nums.size();
        int left = 0, currSum = 0, minLen = INT_MAX;
        for(int right = 0 ; right < n ; right++){
            currSum += nums[right];
            while(currSum >= target){
                    minLen = min(minLen , right - left + 1);
                    currSum -= nums[left];
                    left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};