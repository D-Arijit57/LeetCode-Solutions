class Solution {
public:
    bool canSplit(vector<int>&nums, int mid, int k){
        int n = nums.size();
        // we are starting from split 1
        int cnt_splits = 1, sum = 0;
        for(int i = 0 ; i < n ; i++){
            // if we have our target sum, start a new split
            if(sum + nums[i] > mid){
                cnt_splits++;
                sum = 0;
            }
            sum += nums[i];
        }        
        // check if the splits
        // are not more than the desired splits
        return cnt_splits <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        // egde case : if the size of the subarrays we need is more than the total size of the array then it's impossible to make splits
        if(k > nums.size()) return -1;
        // search space here is the sum 
        // starting from the highest element
        // as the split or the partition or subarray should be able to contain the largest element itself
        int n = nums.size();
        // the maximum a split can hold (k = 1) is the total sum of all the elements in the array
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        int low = *max_element(nums.begin(), nums.end()), high = sum;
        int ans = INT_MAX;
        while(low <= high){
            // mid represents the sum
            int mid = low + (high - low) / 2;
            // search is monotonic :  F F F T T T


            // if this sum satifies the split : if the array can be splitted in such a way
            // that this sum can be justified we can for sure say its large enough and we can look for a smaller sum
            if(canSplit(nums,mid,k)){
                ans = mid;
                high = mid - 1;
            }
            // if it doesn't satistfy then its too small
            // and it doesn't justify the number of splits we can have in this array
            // so we need to look for a larger sum
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};