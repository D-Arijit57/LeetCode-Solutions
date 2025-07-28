class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
          // Find maximum possible OR
        int maxOR = 0;
        for (int num : nums) {
            maxOR |= num;
        }
        
        return backtrack(nums, 0, 0, maxOR);
    }
    
private:
    int backtrack(vector<int>& nums, int index, int currentOR, int maxOR) {
        // Base case: we've considered all elements
        if (index == nums.size()) {
            return (currentOR == maxOR) ? 1 : 0;
        }
        
        // Two choices: include current element or exclude it
        int cnt = 0;
        
        // Exclude current element
        cnt += backtrack(nums, index + 1, currentOR, maxOR);
        
        // Include current element
        cnt += backtrack(nums, index + 1, currentOR | nums[index], maxOR);
        
        return cnt;
    }
};