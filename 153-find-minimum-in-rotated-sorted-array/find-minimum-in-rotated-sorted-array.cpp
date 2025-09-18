class Solution {
public:
    int findMin(vector<int>& nums) {
      int n = nums.size();
      int low = 0 , high = n - 1;
      int mini = INT_MAX;
      while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[low] <= nums[high]){
            mini = min(mini,nums[low]);
            break;
        }
        else if(nums[low] <= nums[mid]){
            mini = min(mini,nums[low]);
            low = mid + 1;
        }
        else {
            mini = min(mini, nums[mid]);
            high = mid - 1;
        }
        
      }
      return mini;
    }
};