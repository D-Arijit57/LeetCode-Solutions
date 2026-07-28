class Solution {
public:
    bool canSplit(vector<int>&nums, int limitSum, int k){
        int n = nums.size();
        int currSum = 0, splitCnt = 1;
        for(int i = 0 ; i < n ; i++){
            // if we can fit the current element within the limit
            // add it
            // delay the start of the new split as long as possible - * Greedy Choice *
            if(currSum + nums[i] <= limitSum){
                currSum += nums[i];
            }
            // if we can't fit the current element within the limit
            // start a new split
            else{
                currSum = nums[i];
                splitCnt++;
            }
        }
        return splitCnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        // edge case : if number of subarrays are more than total elements in the array
        // we cannnot create the splits, because there aren't enough elements to split into 
        // non-empty subarrays
        if(k > nums.size()) return -1;
        // the search space belongs from the largest element to total sum of all elements in the array
        // since the splits are supposed to be non-empty one split should have atleast one element, it should be capable of holding the largest element 
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low < high){
            // mid represents the maximun sum candidate
            int mid = low + (high - low) / 2;
            // if the current sum is feasible, then find a smaller sum
            if(canSplit(nums, mid, k)){
               high = mid;
            }
            // if its not then its too small to create the k splits, find a larger sum
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};