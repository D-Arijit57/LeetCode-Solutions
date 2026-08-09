class Solution {
public:
// We maintain normal Kadane for the 0-deletion state, and a second state for the exactly-1-deletion state. At the end, we take the best result from either state, because the deletion is optional.
    int maximumSum(vector<int>& arr) {
        // the main perspective here is : What is the best subarray sum ending at index i under each deletion condition ?
        int n = arr.size();

        // the deletion is optional, that too is once
        // we should no_delete the sum with the highest value
        int no_delete = arr[0], ans = arr[0], one_delete = 0;
        // how can exactly one deletion happen at index i ?
        // conceptually if the current element gets one_delete we are left with the sum of the previous subarray without the current one
        // that is the previous_no_delete
        for(int i = 1 ; i < n ; i++){
            int previous_no_delete = no_delete;
            int previous_one_delete = one_delete;
            // we have to deletion conditions either one delete or no delete
            // so if there's no deletion we can extend the preivous subarray sum
            // if there's deleteion then we can delete the current one and move forward with the previous subarray sum 

            // what we are doing is considering the specific location at each index for that one deletion
            one_delete = max(previous_no_delete, previous_one_delete + arr[i]);
            
            // base kadane's checking if it should start a new sum or extend the previous one
            no_delete = max(arr[i],  previous_no_delete + arr[i]);        
            
            // check if the maximum sum is with one deletion or no deletion till this index i 
            ans = max({ans, no_delete ,one_delete});
        }
        return ans;
    } 
};