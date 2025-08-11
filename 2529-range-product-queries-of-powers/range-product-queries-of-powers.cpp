class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        
        // Extract exponents from n's binary representation
        vector<int> exponents;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                exponents.push_back(i);
            }
        }
        
        // Precompute prefix sums for efficient range sum queries
        vector<long long> prefixSum(exponents.size() + 1, 0);
        for (int i = 0; i < exponents.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + exponents[i];
        }
        
        // Helper function for fast modular exponentiation
        auto fastPow = [&](long long base, long long exp) -> long long {
            long long result = 1;
            while (exp > 0) {
                if (exp & 1) {
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
                exp >>= 1;
            }
            return result;
        };
        
        // Process queries
        vector<int> result;
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            // Calculate sum of exponents in range [left, right]
            long long totalExponent = prefixSum[right + 1] - prefixSum[left];
            
            // Calculate 2^totalExponent mod MOD
            result.push_back(fastPow(2, totalExponent));
        }
        
        return result;
    }
};