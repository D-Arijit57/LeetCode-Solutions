class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0] = 1; // prefix sum 0 has occured 1 time (starting position)

        int currPrefix = 0;
        int cnt = 0;

        for(int x : nums){
            currPrefix += x;

            if(mp.count(currPrefix - k)){
                cnt += mp[currPrefix - k];
            }

            mp[currPrefix]++;
        }
        return cnt;

    }
};