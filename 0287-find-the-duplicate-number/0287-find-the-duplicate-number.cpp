class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ; 
        // place each number at its correct index
        while( i < n ){
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]){
                swap(nums[i], nums[correctIndex]);
            }
            else i++;
        }
        // re-check
        // for a range 1 to N, 
        // the value x should be at index x-1
        for(int i = 0 ; i < n ; i++){
            if(i != nums[i] - 1) return nums[i];
        }
        return n;
    }
};