class Solution {
public:
    int atMost(vector<int>&nums,int k){
        int n = nums.size();
        unordered_map<int,int>freq;
        int cnt = 0 ;
        int left = 0;
        for(int right = 0 ; right < n ; right++){
            freq[nums[right]]++;
            while(freq.size() > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt ;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};