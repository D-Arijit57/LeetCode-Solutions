class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // using maps this time
        
        // int n = nums.size();
        // unordered_map<int, int>freq;
        // int left = 0, maxLen = 0;
        // for(int right = 0 ; right < n ; right++){
        //     freq[nums[right]]++;
        //     if(nums[right] == 0){
        //         while(freq[nums[right]] > k){
        //             freq[nums[left]]--;
        //             left++;
        //         }
        //     }
        //     maxLen = max(maxLen , right - left + 1);          
        // }
        // return maxLen;

        // since we know we only need to count 
        // and check if the number of zeros > k (to skip invalid window)
        // we can just keep a counter for the zero
        int n = nums.size();
        int left = 0, zeroCnt = 0, maxlen = 0;
        for(int right = 0 ; right < n ; right++){
            if(nums[right] == 0) zeroCnt++;
            while(zeroCnt > k){
                if(nums[left] == 0) zeroCnt--;
                left++;
            }
            maxlen = max(maxlen , right - left + 1);
        }
        return maxlen;
    }
};