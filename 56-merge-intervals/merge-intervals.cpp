class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // we should sort the intervals in increasing order
        // or else the ones that start before an interval would be missed
        // e.g [[4,7],[1,4]] 
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < n ; i++){
            // if the incoming interval overlaps
            // merge it
            // the end becomes max end between two of the intervals
            // because then only it can cover the overlapped inteval
            if( ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            // if they don't overlap simply push the interval into the ans
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};