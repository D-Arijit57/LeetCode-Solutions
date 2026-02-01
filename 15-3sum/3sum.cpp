class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        // since we are checking triplets it makes no sense to iterate till n
        // we can just iterate till n - 2 positions    
        for(int i = 0 ; i < n-2 ; i++){
            // skipping duplicates since it would lead to duplicate triplets
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int left = i + 1 , right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0) right--;
                else if(sum < 0) left++; 
                else { // when sum is equal to the target
                    ans.push_back({nums[i],nums[left],nums[right]});
                    // skipping the duplicates
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};