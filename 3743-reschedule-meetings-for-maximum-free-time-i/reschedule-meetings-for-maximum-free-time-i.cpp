class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        // Gap before the first meeting
        gaps.push_back(startTime[0]);
        // Gaps between meetings
        for (int i = 1; i < n; ++i) {
            gaps.push_back(startTime[i] - endTime[i-1]);
        }
        // Gap after the last meeting
        gaps.push_back(eventTime - endTime[n-1]);
        
        int maxFree = 0;
        int window = k + 1;
        int sum = 0;
        // Initial window
        for (int i = 0; i < window && i < gaps.size(); ++i) {
            sum += gaps[i];
        }
        maxFree = sum;
        // Slide the window
        for (int i = window; i < gaps.size(); ++i) {
            sum += gaps[i] - gaps[i - window];
            maxFree = max(maxFree, sum);
        }
        return maxFree;
    }
};