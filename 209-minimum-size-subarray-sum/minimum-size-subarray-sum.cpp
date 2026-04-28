class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, minLen = INT_MAX, sum = 0;
        for(int right = 0 ; right < n ; right++){  
            // add the number to the sum  
            sum += nums[right];

            // since we already found a sum greater than the target
            // we need to find a closer one 
            // the lesser the size of the subarray the lesser to the sum
            while(sum >= target){
                // update first or else you'll miss the valid windows
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++; 
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};