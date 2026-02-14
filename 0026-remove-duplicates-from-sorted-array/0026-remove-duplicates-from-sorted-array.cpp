class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = left + 1;
        while(right < n){
            if(nums[left] == nums[right]){
                right++;
            }
            else{
                swap(nums[left + 1], nums[right]);
                left++;
                right++;
            }
        }
        return left + 1;
    }
};