class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int maxLen = 0;
        int left = 0;
        for(int right = 0 ; right < n ; right++){
            freq[nums[right]]++;
            if(nums[right] == 0){
                while(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
                }
            }
            maxLen = max(maxLen , right - left + 1);
        }
        return maxLen;
    }
};