class Solution {
public:
     int mod = 1e9+7;
           int helper(int i, int n, int m, int k,vector<vector<vector<int>>> &dp){
          if(n<=0){
              if( k == 0) return 1;
              return 0;
          }
          if(dp[i][n][k]!=-1) return dp[i][n][k];
          int ans = 0;
          for(int j = 1 ; j<=m ; j++){
              if(j > i){
                  if(n>=1 && k>=1){
                      ans = (ans + helper(j, n-1 , m , k-1 , dp))%mod;
                  }
              }
              else{
                  if(n>=1){
                      ans = (ans + helper(i , n-1, m , k , dp)) % mod;
                  }
              }
          }

          return dp[i][n][k] = ans % mod;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp (m+1 , vector<vector<int>>(n+1, vector<int>(k+1,-1)));
        return helper(0,n,m,k,dp);
    }
};