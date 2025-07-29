class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        // For each bit position, store the rightmost index where this bit is 1
        vector<int> lastPos(32, -1);
        
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Update last positions for bits that are set in nums[i]
            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit)) {
                    lastPos[bit] = i;
                }
            }
            
            // Find the farthest position we need to reach to get maximum OR
            int maxReach = i; // At minimum, we include the current element
            for (int bit = 0; bit < 32; bit++) {
                if (lastPos[bit] != -1) {
                    maxReach = max(maxReach, lastPos[bit]);
                }
            }
            
            result[i] = maxReach - i + 1;
        }
        
        return result;
    }
};