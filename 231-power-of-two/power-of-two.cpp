class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A power of two has exactly one bit set
        // For example: 1=001, 2=010, 4=100, 8=1000
        // Key insight: n & (n-1) removes the rightmost set bit
        // For powers of 2, this results in 0
        // Also need to check n > 0 to handle negative numbers and 0
        return n > 0 && (n & (n - 1)) == 0;
    }
};