class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() <= 1) return nums[0];
        // since the array is sorted and rotated
        // there could be one rotation point only
        // that point is the minimum element
        // so we need to check if [low....mid] is sorted or not
        // if it does then either the low is the minimum if the array is entirely sorted
        // otherwise the rotation point cannot exist in between the segment for sure
        // so we eliminate that segment
        // if nums[low] <= nums[mid]
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            // eliminate the half where [mid....high] where the rotation point cannot exist
            // if its strictly increasing
            if(nums[mid] <= nums[high]){
                high = mid;
            }
            // if nums[mid] > nums[high] the rotation point exists somewhere between [mid...high]
            else low = mid + 1;
        }
        return nums[low];
    }
};