class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, maxSum = 0, currentSum = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // If current element is already in the window, shrink from left
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }
            
            // Add current element to the window
            seen.insert(nums[right]);
            currentSum += nums[right];
            
            // Update maximum sum
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};