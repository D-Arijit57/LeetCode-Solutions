class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // closest sum means the difference between the sum and the target is minimum
        // so we are actually looking for the sum where the distance will be minimum
        // if we find the target we immadiately return it
        // otherwise doesn't matter if its greater or smaller we always update the distance
        // if the current distance is the new smallest one compared to the one we have seen so far
        // the basic principle stays the same because monotonicity of sorted space
        // that is if we find a sum that is smaller than the target we go right
        // if its greater we go left
        // as the more we go right there are increasing elements
        // the more we go left there are decreasing elements
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX, ans = 0;
        for(int i = 0 ; i < n ; i++){
            int left = i + 1, right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(target - sum);
                if(diff < minDiff){
                    ans = sum;
                    minDiff = diff;
                }
                if(sum > target) right--;
                else if(sum < target) left++;
                else return sum;
            }
        }
        return ans;
    }
};