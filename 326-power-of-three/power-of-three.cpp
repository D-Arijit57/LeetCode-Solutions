class Solution {
public:
    bool isPowerOfThree(int n) {
       // Handle edge cases
        if (n <= 0) return false;
        if (n == 1) return true;  // 3^0 = 1, so 1 is a power of 3
        
        // Check if n is divisible by 3, if not, it's not a power of 3
        if (n % 3 != 0) return false;
        
        // Recursively check n/3
        return isPowerOfThree(n / 3);
    }
};