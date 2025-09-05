class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // Try different numbers of operations k
        for (int k = 1; k <= 50; k++) {
            // Calculate target = num1 - k * num2
            // This is the sum of k powers of 2 we need
            long long target = (long long)num1 - (long long)k * num2;
            
            // Check if target is valid:
            // 1. Must be positive (sum of powers of 2)
            // 2. Must be at least k (minimum: k ones)
            // 3. Must have at most k bits set (we have k operations)
            if (target > 0 && target >= k && __builtin_popcountll(target) <= k) {
                return k;
            }
        }
        
        return -1; 
    }
};