class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
// When two intervals overlap,
// keeping the interval with the smaller end
// leaves the maximum room for future intervals.
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int cnt = 0;
        // keeping the track of previous end
        // because that's all we need to check if the interval overlaps and which interval to keep
        int prevEnd = intervals[0][1];
        for(int i = 1 ; i < n ; i++){
            int currentStart = intervals[i][0];
            // Overlap : 
            // if currenStart < prevEnd
            if(currentStart < prevEnd){
                cnt++;
                // keep the one which ends earlier
                prevEnd = min(prevEnd , intervals[i][1]);
            }
            // No overlap : update the prevEnd
            else{
                prevEnd = intervals[i][1];
            }
        }
    return cnt;
    }
};