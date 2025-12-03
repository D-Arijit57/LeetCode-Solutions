#define v vector
#define ll long long
class Solution {
public:
    v<int> shuffle(v<int>& nums, int n) {
        v<int>ans;
      int left = 0 , right = n ;
      while(right < nums.size()){
        ans.push_back(nums[left]);
        ans.push_back(nums[right]);
        left ++;
        right ++;
      }
      return ans;
    }
};