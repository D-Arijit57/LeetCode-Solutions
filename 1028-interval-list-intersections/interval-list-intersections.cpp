class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // intersection is defined by :
        // {max(start), min(end)}
        // we can only find the intersection if two intervals overlap otherwise we can't
        // two intervals overlap when first.end >= second.start
        int n = firstList.size();
        int m = secondList.size();
        if(m == 0  || n == 0) return {};
        vector<vector<int>>ans;
        int left = 0, right = 0;
        while( left < n && right < m){
            int start1 = firstList[left][0];
            int start2 = secondList[right][0];
            int end1 = firstList[left][1];
            int end2 = secondList[right][1];
            // if they overlap
            // one interval might have intersections with multiple intervals
            // overlap condition only when start1 <= end2 && start2 <= end1
            if(start1 <= end2 && start2 <= end1){
                // find the intersection and push it in the ans
                int intersection_start = max(firstList[left][0], secondList[right][0]);
                int intersection_end = min(firstList[left][1], secondList[right][1]);
                ans.push_back({intersection_start,intersection_end});
            }
            // move the pointer which interval end's first
            if(end1 <= end2) left++;
            else right++;
        }
        return ans;
    }
};