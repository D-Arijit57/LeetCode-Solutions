class Solution {
public:
    bool canSplit(vector<int>&nums, int candidate_sum, int k){
        int n = nums.size();
        int cntSplit = 1, sum = 0;
        for(int i = 0 ; i < n ; i++){
            // the moment it crosses the candidate sum
            // we need to start a new split
            if(sum + nums[i] > candidate_sum){
                sum = nums[i];
                cntSplit++;
                if(cntSplit > k) return false;
            }
            // if it's lesser than the
            else sum += nums[i];
        }
        // check if we can have the desired number of splits
        // to form the candidate sum
        return true;
    }
    int splitArray(vector<int>& nums, int k) {      
        // pick a sum
        // starting from a single element and going till the sum of all elements
        // and check if the given k
        // can be used to to form valid splits
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end()), high = 0;
        for(int i = 0 ; i < nums.size(); i++){
            high += nums[i];
        }
        while(low < high){
            int mid = low + (high - low) / 2;
            // if the given sum is satisfied look for a smaller sum
            // since we want it to be minimized
            if(canSplit(nums, mid, k)){
                high = mid;
            }
            // if not then look for a larger sum
            else low = mid + 1;
        }
        return high;
  }
};