class Solution {
public:
    int search(vector<int>& nums, int target) {
        // while being inside [mid...high] determine if the target can exist in that interval
        // same with [low...mid]
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // [mid ... high] is sorted
            // no rotation point inside
            // determine if the target is inside [mid...high]
            if(nums[mid] <= nums[high]){
                if(nums[mid] == target) return mid;
                // if the target is inside [mid...high]
                else if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                // otherwise
                else high = mid - 1;
            }
            // [mid...high] is not sorted
            // there is a rotation point
            // determine if the target belong inside [low...mid]
            else {
                if(nums[mid] == target) return mid;
                // if the target is inside [low...mid]
                else if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                // otherwise
                else low = mid + 1;
            }
        }
        return -1;
        }
};