class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int minDiff = INT_MAX, ans = 0;
        for(int i = 0 ; i < n ; i++){
            if( i > 0 && nums[i] == nums[i-1]) continue; // skipping the duplicates
            int left = i + 1, right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target){
                    return sum;
                }
                // since there can be negatives we will use abs function 
                // as we know only the distance matters irrespective of the sign convention
                int currDiff = abs(sum - target);
                if(currDiff < minDiff){
                    ans = sum;
                    minDiff = currDiff;
                }
                else if(sum > target){
                     right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};