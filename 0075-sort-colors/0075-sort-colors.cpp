class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dutch national flag algorithm
        int n = nums.size();
        int left = 0, mid = left , right = n - 1;
        while(mid <= right){
            if(nums[mid] == 1) mid++;
            else if(nums[mid] == 2) {
                swap(nums[right], nums[mid]);
                right--;
            }
            else {
                swap(nums[left] , nums[mid]);
                left++;
                mid++;
            }
        }
    }
};