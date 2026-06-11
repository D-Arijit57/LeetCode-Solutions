class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // invariant :
        // currOddCount - OldOddCount == k
        int n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = 1;
        int cnt = 0, prefix = 0;
        for(int i = 0 ; i < n ; i++){
            prefix += nums[i] % 2;
            int req = prefix - k;
            if(mp.count(req)) cnt += mp[req];
            mp[prefix]++;
        }
        return cnt;
    }
};