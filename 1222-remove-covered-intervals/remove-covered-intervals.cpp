class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort in order where start = ascending and end = descending
        // we need a custom comparator because the default sort cannot express
        // Because if we processed [1,4] first, we’d miss that it is covered by [1,5].
        sort(intervals.begin(), intervals.end(),
        // compare interval a and interval b
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // end descending
                 return a[0] < b[0]; // start ascending
             });
        // by sorting in this manner
        // we are eliminating the need to compare the starts from now on
        // since the starts are in ascending order
        // there is no way the current start, is covered by any interval later in the list
        // since the current start will always be <= the next one
        // so we need to just take care of the ends
        // Since starts are already processed in ascending order,
        // the only remaining condition for coverage is whether the
        // current interval extends beyond the farthest end seen so far.
        int n = intervals.size();
        int removed = 0;
        // we just need the interval that has been farthest seen so far
        // we can represent the end with just one vaiable
        int maxEnd = INT_MIN;
        maxEnd = intervals[0][1];
        for (int i = 1; i < n; i++) {
            // check if the current intervals covered the last one
            if (maxEnd >= intervals[i][1]){
                // counts the removed one
                removed++;
            }
            // if the interval is not covered then it adds up in the remaining one
            // so we need to remember this ones
            // update the variable representing the farthest we have seen so far
            else maxEnd = max(maxEnd, intervals[i][1]);
        }
        // intervals remaining = total - removed
        int remaining = n - removed;
        return remaining;
    }
};