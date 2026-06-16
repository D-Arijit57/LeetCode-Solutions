class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
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
        // find the duplicates
        // since range is 1 to n and there are n+1 numbers there are atleast one duplicate garaunteed
        for(int i = 0; i < n ; i++){
            if(i != nums[i]-1) ans.push_back(nums[i]);
        }
        return ans;
    }
};