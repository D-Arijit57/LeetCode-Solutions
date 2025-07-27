class Solution {
public:
    int countHillValley(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int cnt = 0, n = nums.size();
        for(int i = 1; i < n - 1; i++) {
            // Find closest non-equal neighbor on the left
            int left = i - 1;
            while(left >= 0 && nums[left] == nums[i]) {
                left--;
            }
            // Find closest non-equal neighbor on the right
            int right = i + 1;
            while(right < n && nums[right] == nums[i]) {
                right++;
            }
            // If we found valid neighbors on both sides
            if(left >= 0 && right < n) {
                // Check if it's a hill or valley
                if((nums[i] > nums[left] && nums[i] > nums[right]) ||  // Hill
                   (nums[i] < nums[left] && nums[i] < nums[right])) {  // Valley
                    cnt++; // In both of the cases we count 
                    // Skip all adjacent equal elements to avoid double counting
                    // i-1 < n-1 : since the last and the first position in the array is invalid we are skipping it 
                    while(i + 1 < n - 1 && nums[i + 1] == nums[i]) {
                        i++;
                    }
                }
            }
        }
        
        return cnt;
    }
};