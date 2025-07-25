class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Since we can delete any elements, we should:
        // 1. Keep only positive values (delete all negative/zero values)
        // 2. For each unique value, keep only one occurrence
        // 3. Sum all remaining unique positive values
        
        unordered_set<int> uniquePositives;
        
        // Collect all unique positive values
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                uniquePositives.insert(nums[i]);
            }
        }
        
        // If no positive values exist, we must select one element
        // Choose the maximum element (least negative)
        if (uniquePositives.empty()) {
            int maxElement = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                maxElement = max(maxElement, nums[i]);
            }
            return maxElement;
        }
        
        // Sum all unique positive values
        int totalSum = 0;
        for (int value : uniquePositives) {
            totalSum += value;
        }
        
        return totalSum;
    }
};