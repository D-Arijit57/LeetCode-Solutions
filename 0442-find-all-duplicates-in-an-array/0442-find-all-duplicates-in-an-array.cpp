class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // the problem explicity mentions there are duplicates in the array 
        // " each integer appears at most twice, return an array of all the integers that appears twice"
        int n = nums.size();
        int i = 0; 
        vector<int>ans;
        // sort it up first using cyclic sort
        while(i < n){
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]){
                swap(nums[i],nums[correctIndex]);
            }
            else i++;
        }
        // After Cyclic sort 
        // since the value x should at x-1
        // If nums[i]-1 != i, then the correct value for this position is missing.
        // The value currently sitting here must be a duplicate,
        // because its correct position is already occupied by
        // another copy of the same value.
        for(int i = 0; i < n ; i++){
            if(i != nums[i]-1) ans.push_back(nums[i]);
        }
        return ans;
    }
};