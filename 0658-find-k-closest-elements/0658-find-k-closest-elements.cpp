class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // sliding window + binary search
        if(arr.empty()) return {};

        // since the array is sorted
        // the k closest elements will always form subarray 
        // as consider this window {a ... c ... b}
        // a < c < b, here c cannot be worse than its two endpoints
        // so if b and a are fit for the answer then c is bound to be also a fit for the answer
        // rather trying to find the answer by selecting arbitrary elements
        // what we are trying to find the starting index the window of size k
        // containing the answer array 
        int n = arr.size();
        vector<int>ans;

        // there are total n - k + 1 number of windows in the array
        // and the starting indices ranges from 0...n-k
        // the search space here is the starting indices
        int low = 0, high = n - k;

        // Find the starting index of the optimal window of size k.
        while(low < high){
            int mid = low + (high - low) / 2;    
            // for two windows options {2,3,4} and {3,4,5} how do we decide if we have to move to the window to the right
            // compare abs(x - 2) > abs(5 - x) (distances)
            // but if they are the same
            // pick the smaller element to fit in the window and move the window accordingly
            if(x - arr[mid] > arr[mid + k] - x){
                low = mid + 1;
            }
            else high = mid;
        }

        // after finding the starting of our answer window for using binary search
        // extract the elements
        for(int i = low ; i < low + k ; i++){
            ans.push_back(arr[i]);
        }
        
        return ans;

    }
};