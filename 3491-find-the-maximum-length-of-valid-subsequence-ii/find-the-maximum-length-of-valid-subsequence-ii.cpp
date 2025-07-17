class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        
        // Try all possible target sums modulo k
        for (int targetSum = 0; targetSum < k; targetSum++) {
            // dp[r] = maximum length of valid subsequence ending with remainder r
            vector<int> dp(k, 0);
            
            for (int i = 0; i < n; i++) {
                int currRem = nums[i] % k;
                
                // Start a new subsequence with this element
                int newLen = 1;
                
                // Try to extend from the remainder that would make the sum equal targetSum
                int prevRem = (targetSum - currRem + k) % k;
                if (dp[prevRem] > 0) {
                    newLen = max(newLen, dp[prevRem] + 1);
                }
                
                dp[currRem] = max(dp[currRem], newLen);
            }
            
            // Find the maximum length for this target sum
            for (int r = 0; r < k; r++) {
                maxLen = max(maxLen, dp[r]);
            }
        }
        
        return maxLen;
    }
};