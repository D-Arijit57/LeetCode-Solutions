class Solution {
public:
    int search(vector<int>& nums, int target) {
        // we can find the rotations point 
        // as well as how many times it was rotated by low + 1
        // if we are outside the rotation point boundary that is mid <= high
        // and high > target the it cannot exist in that boundary
        // similary if we are inside the rotation point if nums[mid] > nums[high]
        // and low > target it cannot be on the left side 
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