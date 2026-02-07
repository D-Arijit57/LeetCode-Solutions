class Solution {
public:
    void sortColors(vector<int>& nums) {
              // dutch national flag algorithm
              // mid == 1 keep moving forward
              // mid == 0 swap with left 
              // mid == 2 swap with right 
              int n = nums.size();
              if(n <= 1) return;
              int left = 0, right = n - 1;
              int mid = left;
              while(mid <= right){
                if(nums[mid] == 1) mid++;
                else if(nums[mid] == 0){
                    swap(nums[mid],nums[left]);
                    left++;
                    mid++;
                }
                else{
                    swap(nums[mid],nums[right]);
                    right--;
                }
            } 
    }
};