#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        // A boolean array to act as a frequency map for seen numbers.
        // The size is 10001 because the constraints are 1 <= nums[i] <= 10^4.
        std::vector<bool> seen(10001, false);
        
        int left = 0;
        int max_score = 0;
        int current_sum = 0;

        // Use the 'right' pointer to expand the window.
        for (int right = 0; right < nums.size(); ++right) {
            int current_num = nums[right];

            // If the current number is already in the window,
            // shrink the window from the left until the duplicate is removed.
            while (seen[current_num]) {
                int left_num = nums[left];
                current_sum -= left_num;
                seen[left_num] = false;
                left++;
            }

            // Add the current number to the window.
            current_sum += current_num;
            seen[current_num] = true;

            // Update the maximum score found so far.
            max_score = std::max(max_score, current_sum);
        }

        return max_score;
    }
};