class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            // these two following conditions makes sure
            // we are peaking sure we are always moving towards the space
            // where at least a peak exists
            if(arr[mid] < arr[mid + 1]) {
            
                low = mid + 1 ;
            }
            else{
                
                high = mid;
            } 
        }
        return low;
    }
};