class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
         int n = nums.size();
         int left = -1;
         int right = -1;
         int maxSeen = nums[0];
         int minSeen = nums[n-1];
         // setting the boundary for the right side 
         // for each element first update the maxSeen
         // since we are checking for global anomaly 
         // check if its lesser than the maxSeen
        for(int i = 1 ; i < n ; i++){
            maxSeen = max(maxSeen,nums[i]);
            if(maxSeen > nums[i]) right = i;            
        }
        // setting the boundary for the left side
        // for each element update the minSeen
        // check if the current element is greater than the minSeen
        for(int j = n - 2 ; j >= 0 ; j--){
            minSeen = min(minSeen,nums[j]);
                if(minSeen < nums[j]) left = j;
        }
        // since the boundary has been marked 
        // return the length of the subarray by right - left + 1
        if(right == -1) return 0;
        return right - left + 1; 
    }
}; 