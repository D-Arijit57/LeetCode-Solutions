class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        // invariant : 
        // number of zeros in the window <= k
        // if it becomes >k , then trim from the left side
        int cntZero = 0, left = 0;
        int max_len = INT_MIN;
        for(int right = 0 ; right < n ; right++){
            if(nums[right] == 0) cntZero++;

            // shrink the window 
            // when it breaks the invariant
            while(cntZero > k){
                if(nums[left] == 0) cntZero--;
                left++;
            }

            // for the valid window
            // update the new length (for the longest consecutive ones we have seen till now)
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};