class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // we shrink it when it is valid to find a smaller window
        // rather than when it is invalid
        int n = nums.size();
        int left = 0, minLen = INT_MAX, currSum = 0;
        for(int right = 0 ; right < n ; right++){
            currSum += nums[right];
            while(currSum >= target){
                // We update inside the loop because 
                // every intermediate shrink still represents a valid window
                // and we want the smallest among them.
                minLen = min(minLen, right - left + 1);
                currSum -= nums[left];
                left++;
            }
        } 
        return minLen == INT_MAX ? 0 : minLen; 
    }
};