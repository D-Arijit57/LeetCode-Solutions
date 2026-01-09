class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>>res;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            // check for same element beforehand to avoid duplicates
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1 , right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0) right--;
                else if(sum < 0) left++;
                if(sum == 0){
                    vector<int>triplets = {nums[i],nums[left],nums[right]};
                    res.push_back(triplets);
                    // to avoid the repeatation of same element by left and right
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};