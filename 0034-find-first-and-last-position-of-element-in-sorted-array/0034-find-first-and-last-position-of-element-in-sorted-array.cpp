class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        // basically find the upper and lower bound of a given element
        // two binary searches
        // one for lower and one for upper
        // O(log n) + O(log n) = O(log n)
        int n = nums.size();
        int low = 0, high = n;
        vector<int>ans;
        // since strictly increasing order
        // to find the first occurence once you find the first instance move left from there
        // to find the last occurence you move right towards the end

        // first binary search for the lower bound
        while(low < high){
            int mid = low + (high - low) / 2;

            // if the current element is greater or equal keep it
            if(nums[mid] >= target){
                high = mid;
            }
            // if it's smaller eliminate the left search space
            else low = mid + 1;
        }
        // if the element doesn't exist at all
        // at the end low should be pointing towards the lower bound
        // if nums[low] != target
        // the element doesn't exist
        if(nums[low] != target) return {-1,-1};

        ans.push_back(low);
        // second binary search for the upper bound
        low = 0, high = n; 
        while(low < high){
            int mid = low + (high - low) / 2;
            // if the element is strictly greater
            // eliminate the right half 
            // this condition correctly finds the first element where nums[mid] > target
            // but since we are looking for the element where it's = target
            // it should high - 1
            // basically just before the current one
            if(nums[mid] > target) high = mid;
            // if the element is smaller or equal
            // eliminate the left half
            // but keep the mid
            else low = mid + 1;
        }
        // push the answer
        ans.push_back(high - 1);
        return ans;
    }
};