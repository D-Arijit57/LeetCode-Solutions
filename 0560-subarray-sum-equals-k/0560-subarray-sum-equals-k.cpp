class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // currPrefix - OldPrefix == k
        // OldPrefix =  currPrefix - k 
        // using a prefix sum method
        // if the difference between left and right boundary is k
        // then the sum of the elements between those boundary is equal to k
        // by expressing this mathematically
        // we are going to solve this problem
        // if you find the required prefix already in the map 
        // we add up the frequency to the ans (how many times we have seen this)
        // if we haven't then we just update the frequency in the map 
        int n = nums.size();
        unordered_map<int, int>prefix;
        int ans = 0, sum = 0;

        // sum of 0 appears before the array even starts
        // initial state of sum 
        prefix[0] = 1;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];

            int req = sum - k;

            // if it does exist in the map
            // add its frequency to the answer
            if(prefix.count(req)) ans += prefix[req];

            // if it doesn't exist in the map
            // update its frequency in the map
            prefix[sum]++;
        }
       return ans;
    }
};