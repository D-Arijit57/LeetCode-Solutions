class Solution {
public:
    double soupServings(int n) {
        // For large n, the probability approaches 1 due to bias towards emptying A first
        // This optimization is crucial for the constraint n <= 10^9
        if (n >= 4800) return 1.0;
        
        // Convert to units of 25ml to reduce state space
        // Since all operations are multiples of 25, we can work with smaller numbers
        int units = (n + 24) / 25;  // Ceiling division
        
        // Memoization map: (a_units, b_units) -> probability
        unordered_map<long long, double> memo;
        
        return solve(units, units, memo);
    }
    
private:
    double solve(int a, int b, unordered_map<long long, double>& memo) {
        // Base cases
        if (a <= 0 && b <= 0) return 0.5;  // Both empty simultaneously
        if (a <= 0) return 1.0;            // A empty first
        if (b <= 0) return 0.0;            // B empty first
        
        // Check memo
        long long key = ((long long)a << 32) | b;
        if (memo.count(key)) return memo[key];
        
        // Four operations with equal probability (0.25 each):
        // 1. Pour 100ml from A, 0ml from B    -> (a-4, b-0)
        // 2. Pour 75ml from A, 25ml from B    -> (a-3, b-1)  
        // 3. Pour 50ml from A, 50ml from B    -> (a-2, b-2)
        // 4. Pour 25ml from A, 75ml from B    -> (a-1, b-3)
        
        double result = 0.25 * (
            solve(max(0, a-4), max(0, b-0), memo) +
            solve(max(0, a-3), max(0, b-1), memo) +
            solve(max(0, a-2), max(0, b-2), memo) +
            solve(max(0, a-1), max(0, b-3), memo)
        );
        
        memo[key] = result;
        return result;
    }
};