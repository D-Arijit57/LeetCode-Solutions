class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCount = 0, oddCount = 0;
        
        // Count even and odd numbers
        for (int num : nums) {
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        // Pattern 1: All even numbers (even + even = even)
        int allEven = evenCount;
        
        // Pattern 2: All odd numbers (odd + odd = even)
        int allOdd = oddCount;
        
        // Pattern 3: Alternating even-odd (even + odd = odd)
        // Greedily pick elements that maintain alternating pattern starting with even
        int altEvenFirst = 0;
        bool expectEven = true; // Start expecting even
        for (int num : nums) {
            if ((num % 2 == 0) == expectEven) {
                altEvenFirst++;
                expectEven = !expectEven; // Toggle expectation
            }
        }
        
        // Pattern 4: Alternating odd-even (odd + even = odd)
        // Greedily pick elements that maintain alternating pattern starting with odd
        int altOddFirst = 0;
        bool expectOdd = true; // Start expecting odd
        for (int num : nums) {
            if ((num % 2 == 1) == expectOdd) {
                altOddFirst++;
                expectOdd = !expectOdd; // Toggle expectation
            }
        }
        
        return max({allEven, allOdd, altEvenFirst, altOddFirst});
    }
};