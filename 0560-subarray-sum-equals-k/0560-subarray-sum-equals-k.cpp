class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // for prefix sum we know : 
        // for a range from l to r : 
        // sum at index r is prefix[r] - prefix[l - 1]
        // i.e currPrefix - oldPrefix
        // here the key logic is :
        // we have to find sum where :  prefix[r] - prefix[l - 1] = k = sum
        // so if you think in a reverse engineering way :
        // we can try to find prefix[l-1] such that prefix[l - 1] = prefix[r] - k
        // mathematically it would satisfy the condition and we can count that as a valid subarray  

        unordered_map<int, int>mp;
        mp[0] = 1; // prefix sum 0 has occured 1 time (starting position)
        // incase we don't keep it we would miss the valid subarray starting at index 0
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