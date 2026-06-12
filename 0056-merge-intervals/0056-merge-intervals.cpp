class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort so that we can identify if there are any overlaps
        // to find if there is any interval : 
        // if (currentFirst <= mergedLast) then merge
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size(); i++){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};