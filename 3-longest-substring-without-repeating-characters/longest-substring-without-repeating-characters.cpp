class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // since we want the longest substring without repeating characters 
        // the maximum frequency for each character inside the window would be <= 1
        // for that since right is expanding the window 
        // we will check if the current character right is pointing towards has frequency > 1 or not
        int n = s.size();
        int left = 0, maxLen = 0;
        // since the strings contain a-z,A-Z,0-9 we will initialize with 256
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