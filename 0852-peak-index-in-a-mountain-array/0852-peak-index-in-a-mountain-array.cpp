class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // the core idea is to make sure always eliminate the search space without a peak
        // by doing that in each iteration we always move towards the search space where a peak exists 
        // at the end the remaining element would be a peak 
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            // these two following conditions makes sure
            // we are peaking sure we are always moving towards the space
            // where at least a peak exists
            if(arr[mid] < arr[mid + 1]) 
                low = mid + 1 ;
            // we do this because nums[mid] could be the peak itself
            else high = mid;
        }
        return low;
    }
};