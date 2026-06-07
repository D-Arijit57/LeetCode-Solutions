class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSeen = nums[0], minSeen = nums[n-1];
        int left = 0, right = 0;
        // Moving forward to set the boundary for the right
        for(int i = 0 ; i < n ; i++){
            // A Smaller element shouldn't be in the right side 
            maxSeen = max(maxSeen, nums[i]);
            if(nums[i] < maxSeen){
                left = i;
            }
        }
        // Moving backward to set the boundary for the left 
        for(int i = n - 1; i >= 0 ; i--){
            // A larger element shouldn't be on the left side 
            minSeen = min(minSeen, nums[i]);
            if(nums[i] > minSeen){
                right = i;
            }
        }
        return left == 0 ? 0 : left - right + 1;
    }
};