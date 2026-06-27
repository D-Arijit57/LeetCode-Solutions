class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Currprefix - oldprefix = k
        // currprefix = oldprefix + k or,
        // oldPrefix = currPrefix - k
         int n = nums.size();
         unordered_map<int,int>mp;
         int prefixSum = 0;
         // sum zero is already there before the array started
         mp[0] = 1;
         int cnt = 0;
         for(int i = 0 ; i < n ; i++){
            prefixSum += nums[i];
            int required = prefixSum - k;
            // no need to put a if to check if it exists 
            // if it doesn't exist
            // then it'll simply add zero and doesn't affect the answer
            cnt += mp[required];


            // store the frequency of required
            mp[prefixSum]++;
         }
         return cnt;
    }
};