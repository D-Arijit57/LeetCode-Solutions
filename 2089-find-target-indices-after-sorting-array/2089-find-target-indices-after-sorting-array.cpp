class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low= 0, high = n;
        // find the first occurence
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else high = mid;
        }
        int first = low;

        low = 0 , high = n;
        // find the last occurence
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target){
                low = mid + 1;
            }
            else high = mid;
        }
        int last = low;
        
        vector<int> ans;
        for (int i = first; i < last; i++) {
            ans.push_back(i);
        }
    return ans;
    }
};