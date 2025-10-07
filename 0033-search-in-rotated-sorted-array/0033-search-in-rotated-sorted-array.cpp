class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
       int low = 0 , high = n - 1;
       while(low <= high){
        int mid = low + (high - low) / 2;
        if(target == nums[mid]) return mid;
        // if the element doesn't exist in the left half eliminate the left half
        if(nums[low] <= nums[mid]){
        if(target > nums[mid] || target < nums[low]){
            low = mid + 1;
        }
        else high = mid - 1;
        }
        // if the element doesn't exist in the right half eliminate the right half
        else {
            if(target < nums[mid] || target > nums[high]){
             high = mid - 1;
            }
            else low = mid + 1;
        }
        
       }
       return -1;
    }
};