class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        long long currentZeroCount = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                // Continue counting zeros
                currentZeroCount++;
            } else {
                // End of zero sequence, add contribution
                if (currentZeroCount > 0) {
                    result += currentZeroCount * (currentZeroCount + 1) / 2;
                    currentZeroCount = 0;
                }
            }
        }
        // Handle case where array ends with zeros
        if (currentZeroCount > 0) {
            result += currentZeroCount * (currentZeroCount + 1) / 2;
        }
        
        return result;
    }
};