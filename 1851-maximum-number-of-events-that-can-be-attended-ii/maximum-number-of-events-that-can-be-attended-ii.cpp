class Solution {
public:
   int maxValue(vector<vector<int>>& events, int k) {
       // Sort events by end time
       sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[1] < b[1];
       });
       
       int n = events.size();
       
       // dp[i][j] = maximum value considering events 0..i-1 with at most j events
       vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
       
       for (int i = 1; i <= n; i++) {
           int start = events[i - 1][0];
           int end = events[i - 1][1];
           int value = events[i - 1][2];
           
           // Find the latest event that ends before current event starts
           int prev = findLatestNonOverlapping(events, i - 1);
           
           for (int j = 0; j <= k; j++) {
               // Option 1: Don't take current event
               dp[i][j] = dp[i - 1][j];
               
               // Option 2: Take current event (if we have remaining capacity)
               if (j > 0) {
                   int prevValue = (prev == -1) ? 0 : dp[prev + 1][j - 1];
                   dp[i][j] = max(dp[i][j], prevValue + value);
               }
           }
       }
       
       return dp[n][k];
   }
   
private:
   // Find the latest event that ends before events[currentIndex] starts
   int findLatestNonOverlapping(vector<vector<int>>& events, int currentIndex) {
       int currentStart = events[currentIndex][0];
       int left = 0;
       int right = currentIndex - 1;
       int result = -1;
       
       while (left <= right) {
           int mid = left + (right - left) / 2;
           
           if (events[mid][1] < currentStart) { // end < start (non-overlapping)
               result = mid;
               left = mid + 1;
           } else {
               right = mid - 1;
           }
       }
       
       return result;
   }
};