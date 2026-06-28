class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[left] != nums[right]){
                swap(nums[left+1], nums[right]);
                left++;
                right++;
            }
            else right++;
        }
        return left + 1;
    }
};