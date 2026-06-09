class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int cnt = 0 ;
        // empty check point , subarray can start from the 0th index 
        mp[0] = 1;
        int remainder = 0, prefix = 0;
        for(int i = 0 ; i < n ; i++){
            // keep updating the running sum 
            prefix += nums[i];

            // normalization to tackle the negative numbers
            remainder = ((prefix % k) + k) % k;

            // if the remainder exists then add up its frequency to the count
                if(mp.count(remainder)){
                 cnt += mp[remainder];
                }

            // if it doesn't exist then store and update the frequency of the remainder
            mp[remainder]++;
         }
        return cnt;
        }
};