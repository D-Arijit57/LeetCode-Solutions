class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0, minDiff = INT_MAX;
        for(int i = 0 ; i < n-2 ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = n - 1;
            while(left < right){
                 int sum = nums[i]+nums[left]+nums[right];
                 int currDiff = abs(sum - target);
                 if(currDiff < minDiff){
                    minDiff = currDiff;
                    ans = sum;
                 }
                 if(sum == target) return sum;
                 else if(sum < target) left++;
                 else right--;
            }
        }
        return ans;
     }
};