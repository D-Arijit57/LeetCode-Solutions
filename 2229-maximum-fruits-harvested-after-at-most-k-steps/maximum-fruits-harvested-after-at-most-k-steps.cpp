class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        if (n == 0) return 0;
        
        int maxFruits = 0;
        int left = 0;
        int sum = 0;
        
        // Sliding window approach - O(n) time
        for (int right = 0; right < n; right++) {
            sum += fruits[right][1];
            
            // Shrink window from left while it's invalid
            while (left <= right) {
                int leftPos = fruits[left][0];
                int rightPos = fruits[right][0];
                
                // Calculate minimum steps to cover range [leftPos, rightPos]
                // Strategy 1: startPos -> leftPos -> rightPos
                // Strategy 2: startPos -> rightPos -> leftPos
                int steps1 = abs(startPos - leftPos) + (rightPos - leftPos);
                int steps2 = abs(startPos - rightPos) + (rightPos - leftPos);
                int minSteps = min(steps1, steps2);
                
                if (minSteps <= k) {
                    // Valid window, update max and break
                    maxFruits = max(maxFruits, sum);
                    break;
                } else {
                    // Invalid window, shrink from left
                    sum -= fruits[left][1];
                    left++;
                }
            }
        }
        
        return maxFruits;
    }
};