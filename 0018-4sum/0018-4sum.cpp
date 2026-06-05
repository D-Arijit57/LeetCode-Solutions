#define v vector
#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        v<v<int>>ans;
        for(int i = 0; i < n - 3 ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1 ; j < n - 2 ; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int left = j + 1, right = n - 1;
                while(left < right){
                    ll sum = (ll) nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target) right--;
                    else if(sum < target) left++;
                    else {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]}); 
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};