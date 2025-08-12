class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1000000007;
        
        // Memoization map: key = (remaining_sum, current_base)
        unordered_map<long long, int> memo;
        
        function<int(int, int)> dp = [&](int remaining, int base) -> int {
            // Base cases
            if (remaining == 0) return 1;
            if (remaining < 0) return 0;
            
            // Calculate base^x
            long long power = 1;
            for (int i = 0; i < x; i++) {
                power *= base;
                if (power > remaining) break; // Early termination if power exceeds remaining
            }
            
            // If base^x is greater than remaining, no way to use this or higher bases
            if (power > remaining) return 0;
            
            // Create unique key for memoization
            long long key = ((long long)remaining << 16) | base;
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }
            
            // Two choices: include current base^x or skip it
            int result = 0;
            
            // Choice 1: Include base^x
            result = (result + dp(remaining - power, base + 1)) % MOD;
            
            // Choice 2: Skip base^x
            result = (result + dp(remaining, base + 1)) % MOD;
            
            memo[key] = result;
            return result;
        };
        
        return dp(n, 1);
    }
};