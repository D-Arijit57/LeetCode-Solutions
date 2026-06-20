// Revision June 20th : 
// Mistakes :
// 1. Storing wrong difference instead of the sum
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // before using two pointers we need to make sure the array is sorted
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0, minDiff = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            // skip the same triplets
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = n - 1;
            // find the sum 
            // if sum == target then return
            // otherwise update the difference between the target and the sum
            // the minimum the distance the more closer the sum is 
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(target - sum);

                // once you find a new minimum distance update the answer as well as the minDiff seen till now 
                if(diff < minDiff){
                    minDiff = diff;
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