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
            while(zeroCount > k){
               if(nums[left] == 0) zeroCount--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }   
        return maxLen;
    }
};