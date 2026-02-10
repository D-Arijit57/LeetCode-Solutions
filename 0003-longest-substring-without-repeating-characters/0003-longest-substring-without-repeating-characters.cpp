class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // since we want the longest substring without repeating characters 
        // the max frequency inside the window would be <= 1
        int n = s.size();
        int left = 0, maxLen = 0;
        vector<int>freq(256,0);
        for(int right = 0 ; right < n ; right++){
            freq[s[right]]++;
            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }
            // for each valid window update the maximum length

            maxLen = max(maxLen,  right - left + 1);
        }
        return maxLen;
    }
};