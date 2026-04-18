class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        // instead of using maps 
        // focus on the number of zeros coz that's the only thing we need to replace
        int left = 0 , zeroCount = 0, maxLen = 0;
        for(int right = 0 ; right < n ; right++){
            if(nums[right] == 0){
                zeroCount++;
            }
            // shrinking logic
            // since there could be zeros in the left as well , we need to decrease the zeroCount in that case
            while(zeroCount > k){
               if(nums[left] == 0) zeroCount--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }   
        return maxLen;
    }
};