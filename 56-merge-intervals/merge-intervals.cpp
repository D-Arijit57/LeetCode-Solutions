class Solution {
public:
    // [[1,3],[2,6],[8,10]]
    // [[1,6],[8,10]]
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // edge case : if the interval list is empty
        if(intervals.empty()) return {};


        sort(intervals.begin(), intervals.end());
        // sort by their start time
        // so that we can just compare the previous end and next's start
        // if the new start is smaller than the previous end (it starts before the previous interval ends)
        // then they overlap
        int n = intervals.size();
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < n ; i++){
            // check if they overlap
            if(intervals[i][0] <= ans.back()[1]){
                // if they overalap update the end with the larger one 
                // between the prev end and new end
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            // if they do not overlap
            // push the interval into the answer
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};