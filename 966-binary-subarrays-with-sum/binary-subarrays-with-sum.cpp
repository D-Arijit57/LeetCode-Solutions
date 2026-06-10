class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // remainder won't work since if goal = 0 then it might give division by zero error
        // we don't need to store the indices since we want to find the count of the subarrays not length
        // we need to store frequencies but frequencies of what ?
        // currentPrefix - oldPrefix = goal => currentPrefix = goal - oldPrefix
        int n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = 1;
        int prefix = 0, rem = 0, cnt = 0;
        for(int i = 0 ; i < n ; i++){
            prefix += nums[i];
            int required = prefix - goal;
            if(mp.count(required)){
                cnt += mp[required];
            }
            // mistake : mp[prefix - goal]++, it should update the frequency of current prefix
            mp[prefix]++;
        }
        return cnt;
    }
};