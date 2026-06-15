class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // We can have multiple overlapping intervals
        // what we need to find is the one which is beneficial or best fit 
        // that makes the rest of the intervals non overlapping
        // so think of it like this , if we remove the one that ends later 
        // and keep the one ends earlier
        // it make sures that it doesn't overlap with rest of the ones for sure
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int cnt = 0;
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