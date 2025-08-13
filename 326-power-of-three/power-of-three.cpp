class Solution {
public:
    bool isPowerOfThree(int n) {
        //  ---- with Recurison ----- 
    //    // Handle edge cases
    //     if (n <= 0) return false;
    //     if (n == 1) return true;  // 3^0 = 1, so 1 is a power of 3
        
    //     // Check if n is divisible by 3, if not, it's not a power of 3
    //     if (n % 3 != 0) return false;
        
    //     // Recursively check n/3
    //     return isPowerOfThree(n / 3);
        // ------- Without Recursion --------
        // The largest power of 3 that fits in a 32-bit signed integer is 3^19 = 1162261467
        // If n is a power of 3, then 1162261467 % n should be 0
        return n > 0 && 1162261467 % n == 0;

    }
};