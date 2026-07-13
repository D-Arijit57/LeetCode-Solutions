class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // since the intervals array is sorted
        // there are three cases for the current intervals
        // 1. it starts before the new interval
        // 2. it overlaps with the new interval
        // 3. it starts after the new inteval
        int n = intervals.size();
        vector<vector<int>>ans;
        for(int i = 0 ; i < n ; i++){
            // case 1.  it starts before the new interval
            if(intervals[i][1] < newInterval[0]){
                // push it in the answer array
                ans.push_back(intervals[i]);
            }
            // case 2. its a overlapping interval
            // merge it 
            // why do need to only check intervals[i][0] <= newInterval[1]
            // because we have already handled the case of the intervals[i] starting before newInterval
            // means if the first 'if' fails we already know that intervals[i][1] >= newInterval[0]
            else if(intervals[i][0] <= newInterval[1]){
                // take the minimum start and the maximum end comparatively to the current interval
                // and update the new interval
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
            // if the newInterval now doesn't overlap with anyone push it in the answer array
            else{
                ans.push_back(newInterval);
                // current interval becomes the new interval 
                newInterval = intervals[i];
            } 
        }
        // push the last remaining interval 
        ans.push_back(newInterval);
        return ans;
    }
};