class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // for an index to be pivot index
        // at index i, currPrefix - oldPrefix = 0
        // since the same is same
        int n = nums.size();
        vector<int>prefix(n+1,0);
        // store the prefix sum
        for(int i = 0 ; i < n ; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        
        int left_sum = 0, right_sum = 0;
        for(int i = 0 ; i < n ; i++){
            // left sum will be prefix[i] 
            left_sum = prefix[i]; 
            // right sum will be total - prefix[i + 1]  
            right_sum =  prefix[n] - prefix[i + 1];
            if(left_sum == right_sum) return i;
        }
        return -1;
    }
};