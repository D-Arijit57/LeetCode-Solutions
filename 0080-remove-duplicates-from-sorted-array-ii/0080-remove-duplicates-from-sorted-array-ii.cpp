class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int left = 1 , right = 1;
        int cnt = 1;
        while(right < n){
            if(nums[right] == nums[right-1]) cnt++;
            else cnt = 1;
            if(cnt <= 2){
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};