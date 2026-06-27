class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // curr - old = 0
        // curr = old
        // 0 -> negative, 1 -> positive 
        // if the subarray has equal number of 0s and 1s
        // the subarray sum would be 0
        // target here is 0
        int n = nums.size();
        unordered_map<int, int>mp;
        // before the array starts
        // 0 -> negative
        mp[0] = -1;
        int prefix = 0;
        int maxlen = 0;
        for(int i = 0 ; i < n ; i++){
            // if its positive add, else subtract
            prefix += (nums[i] == 1 ? 1 : -1);

            // store the index, if it doesn't exist in the map
            if(mp.find(prefix) == mp.end())
            mp[prefix] = i;

            // update the maxlen
            // currentIndex - lastwhereyousaw
            maxlen = max(maxlen, i - mp[prefix]);
        }
        return maxlen;
    }
};