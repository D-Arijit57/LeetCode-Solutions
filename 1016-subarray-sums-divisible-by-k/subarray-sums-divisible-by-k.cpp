class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // if ( currPrefix - oldPrefix ) % k == 0
        // then currPrefifx % k = oldPrefix % k
        int n = nums.size();
        unordered_map<int,int>mp;
        // before the array started the sum is 0
        // how many times you have seen 0 till now ?  its 1 
        // we are storing the frequency so we need to store the frequency of sum 0 as 1
        mp[0] = 1;
        int sum = 0, cnt = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            // avoiding negative number by adding a bias
            int req =(( sum % k )+ k) % k;
            // if you find the required other half then count the frequency 
            if(mp.count(req)){
                // Every previous prefix with the same remainder
                // forms a valid subarray ending here
                cnt += mp[req];
            }
            
            mp[req]++;
        }
        return cnt;
    }
};