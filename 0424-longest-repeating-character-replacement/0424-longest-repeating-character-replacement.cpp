class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        // hasharray to store the frequencies of the uppercase characters
        vector<int>freq(26,0);
        int left = 0, maxLen = 0,maxFreq = 0;
        for(int right = 0 ; right < n ; right++){
            // updating each new entry
            freq[s[right] - 'A']++;
            // updating the max freq for the current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            // shrinking logic 
            while((right - left + 1)- maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            // updating the maxlength 
            maxLen = max(maxLen , right - left + 1);
            }
            return maxLen;
        }
};