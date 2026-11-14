class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        // basically find the upper and lower bound of a given element
        // two binary searches
        // one for lower and one for upper
        // O(log n) + O(log n) = O(log n)
        int n = nums.size();
        int low = 0, high = n - 1;
        vector<int>ans(2, -1);
        // since strictly increasing order
        // to find the first occurence once you find the first instance move left from there
        // to find the last occurence you move right towards the end

        // first binary search for the lower bound
        while(low <= high){
            int mid = low + (high - low) / 2;

            // if the current element is greater or equal keep it
            if(nums[mid] > target){
                high = mid - 1;
            }
            // if it's smaller eliminate the left search space
            else if(nums[mid] < target) low = mid + 1;
            // if it meets the target
            // move towards left to find the first index
            else {
                ans[0] = mid;
                high = mid - 1;
            }
        }

        // second binary search for the upper bound
        low = 0, high = n - 1; 
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > target){
              high = mid - 1;
            } 
            else if(nums[mid] < target){
                low = mid + 1;
            }
            // if the it meets the target
            // move towards right to find the last index
            else{
                ans[1] = mid;
                low = mid + 1;
            } 
        }
        return ans;
    }
};