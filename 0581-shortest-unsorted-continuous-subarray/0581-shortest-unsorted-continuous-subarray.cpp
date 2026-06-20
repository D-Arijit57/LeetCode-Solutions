class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
            int n = nums.size();
            int left = -1, right = -1;
            int maxSeen = nums[0],  minSeen = nums[n-1];
            for(int i = 0; i < n ; i++){
                // update the global max
                // any small element shouldn't be in the right in the sorted array 
                maxSeen = max(maxSeen, nums[i]);
                if(nums[i] < maxSeen){
                    right = i;
                }
            }
            for(int i = n-1 ; i >= 0; i--){
                // update the global min 
                // any greater element shouldn't be in the left in the sorted array 
                minSeen = min(minSeen,nums[i]);
                if(nums[i] > minSeen){
                    left = i;
                }
            }
            // if one of them doesn't move then the array is already sorted
            // check if left moved or not
            return left == -1 ? 0 : right - left + 1;
        }
};