class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        // edge case : empty intervals array
        if (occupiedIntervals.empty())
            return {};
        int n = occupiedIntervals.size();
        // sort the intervals
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        // merge the intervals as usual in a new array
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(occupiedIntervals[0]);
        for (int i = 1; i < n; i++) {
            // if it overlap
            if (mergedIntervals.back()[1] + 1 >= occupiedIntervals[i][0]) {
                // take the maximum end
                mergedIntervals.back()[1] =
                    max(mergedIntervals.back()[1], occupiedIntervals[i][1]);
            }
            // otherwise push it if it doesn't overlap
            else
                mergedIntervals.push_back(occupiedIntervals[i]);
        }
        // final answer transformed intervals
        vector<vector<int>> ans;
        // initalize the free interval
        int m = mergedIntervals.size();
        // exlcuding the free interval
        // removing all the numbers from the mergedIntervals
        for (auto& merged : mergedIntervals) {
            // assign left and right
            // as moving forward it would make easier to modify the intervals
            // during transformations
            int l = merged[0];
            int r = merged[1];
            // free interval partially covering the merged interval (left trim)
            // take [B+1,r] |  l - r (mergedInterval), A - B (freeInterval)
            if (l < freeStart) { 
                int leftEnd = min(r, freeStart - 1);
                if (l <= leftEnd) ans.push_back({l, leftEnd});
            }
            // free interval partially covering the merged interval(right trim)
            // take [l,A-1] | l - r (mergedInterval), A - B (freeInterval)
            if (r > freeEnd) {
                int rightStart = max(l, freeEnd + 1);
                if (rightStart <= r) ans.push_back({rightStart, r});
            }
            
        }
        return ans;
    }
};