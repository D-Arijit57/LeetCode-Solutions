class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        
        // dp[i][j] = number of squares with bottom-right corner at (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize first row and column
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0];
            result += dp[i][0];
        }
        
        for (int j = 1; j < n; j++) {
            dp[0][j] = matrix[0][j];
            result += dp[0][j];
        }
        
        // Fill the rest of the dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                result += dp[i][j];
            }
        }
        
        return result;
    }
};