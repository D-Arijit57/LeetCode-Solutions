class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // we need to check only for zeros
        // the count of zeros inside the window should be always <= k
        // if it breaks we should shrink the window
        // why it works ?
        // we are maintainig a window where we make sure the number of zeros stays within <= k, every window where the number of zeros <= k is a valid window , and we only update the maximum length for those valid windows
        // and this also make sure that you don't miss out on any valid window, which means we are sure to find the maximum since we are only updating the maximum number ones (including the flipped one) only for the valid windows
        int n = nums.size();
        int left = 0, zeros = 0;
        int ans = INT_MIN;
        for(int right = 0 ; right < n ; right++){
            // expand the window
            if(nums[right] == 0) zeros++;
            // shrink the window if there are more zeros than ks
            while(zeros > k){
                // since we are shrinking from the left we should decrease the count of zero only if it is zero
                // otherwise it would miscount and decrease even if the left is 1
                if(nums[left] == 0) zeros--;
                left++;                
            }
            // for every valid window, update the maximum length
            ans = max(ans, right - left + 1);
        }      
        return ans;
    }
};