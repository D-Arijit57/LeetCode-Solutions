class Solution {
public:
    int search(vector<int>& nums, int target) {
        // if nums[mid] .. nums[high] is not sorted the rotation point
        // exists somehwere between these two
        // 
        int n = nums.size();
        int low = 0 , high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            
            // if left half is sorted
            // check if your target element can exist in this boundary 
            // or not
            if(nums[low] <= nums[mid]){
                // if the element can exist in the left half
                // we can eliminate the right half
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                else low = mid + 1;
            }   

            // same with the right half
            // check if it is sorted and target element can exist in this boundary or not

            else {
                // if the element can exist in the right half
                // we don't need the left half
                // eliminate it
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return -1;
    }
};