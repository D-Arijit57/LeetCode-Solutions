class Solution {
public:
    int search(vector<int>& nums, int target) {
        // The main idea here is finding only the monotoni search space by discarding the rotation point from it, because of which we can easily apply binary search inside 
        // so everytime we make sure the search we are trying to perform the search in stays monotonic
        
        // find the breaking point
        // nums[low]....nums[mid]....nums[high]
        // for sorted array
        // nums[low] < nums[mid] && nums[mid] < nums[high]
        // for rotated array
        // one of them is broken 
        // so what we do is, we need clarify if we are after the breaking point/rotation point
        // or before it
        // since it's rotated "sorted" array one of the halves is bound to be sorted
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;
            
            // if the left half is sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1 ;
            }
            // if the right half is sorted
            else{
                if(nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};