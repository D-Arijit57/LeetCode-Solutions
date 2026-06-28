class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i = 0 ; i < n - 2 ; i++){
            // skip duplicates
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    // skip duplicates 
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } 
            }
        } 
        return ans;
    }
};