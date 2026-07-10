class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // edge case if the array is empty return {-1,-1}
        if (nums.size() == 0)
            return {-1, -1};
        // if the element at the mid is greater than the target eliminate the
        // right half eliminate the left half otherwise we need to find the
        // valid the rightmost and leftmost target so whenever you find an mid
        // with a value of >= target, you want to find the left most valid
        // position of it so you do high = mid - 1; otherwise you do the same
        // for left whenever it is with a value of <= target
        int n = nums.size();
        int low = 0, high = n - 1;
        vector<int> ans(2, -1);
        // binary search 1 to find the left most valid occurence
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) high = mid - 1;
            else if(nums[mid] < target ) low = mid + 1;
            // whenever its equal to the target
            // update the ans and move towards left to find the left most valid occurence 
            else{
                ans[0] = mid;
                high = mid - 1;
            } 
        }
        low = 0, high = n - 1;
        // binary search 2 to find the right most valid occurence 
        while(low <= high){
            int mid = low  + (high - low) / 2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;    
            // if nums[mid] == target then update the end
            // move towards the right to find the right most valid occurence
            else{
                ans[1] = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
    
};