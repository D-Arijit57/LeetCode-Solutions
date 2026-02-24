class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        for(int i = 0 ; i < n ; i++){
            // calculate how much we need to make the sum 
            int needed = target - nums[i];
            if(mpp.count(needed)){
                // if the needed exist return the indices 
                return {i,mpp[needed]};
            }
            // store the index instead of the frequency 
            mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};