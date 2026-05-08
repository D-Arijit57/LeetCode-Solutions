class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int keep = arr[0];
        // to keep track of the deleted elements
        // either delete the current one or extend by adding it
        int deleted = 0;
        int ans = arr[0];
        for(int i = 1 ; i < n ; i++){
            int prevKeep = keep;
            int prevDeleted = deleted;
            // at each point
            // 1. if the element is not beneficial do not include / delete 
            // 2. if we have already deleted the non beneficial element then include the current one and extend
            deleted = max(prevKeep, prevDeleted + arr[i]);
            // conventional kadane's
            keep = max(arr[i], prevKeep + arr[i]);

            ans = max({ans, keep, deleted});
        }
        return ans;
    }
};