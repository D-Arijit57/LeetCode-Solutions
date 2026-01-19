class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0;
        int left = 0, right = 0;
        int cnt = 0 , prod = 1;
        while(right < n){
            prod *= nums[right];
            while(prod >= k && left <= right){
                prod /= nums[left];
                left++;
            }
            cnt += right - left + 1;
            right++;
    }
     return cnt;
    }
};