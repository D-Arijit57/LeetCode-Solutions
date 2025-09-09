class Solution {
public:
    int bs(vector<int>& nums, int low, int high, int target) {
        if (low > high)
            return -1;
        int mid = low + (high - low) / 2;
        if (nums[mid] > target)
            return bs(nums, low, mid - 1, target);
        else if (nums[mid] < target)
            return bs(nums, mid + 1, high, target);
        else
            return mid;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return bs(nums, 0, n - 1, target);
    }
};