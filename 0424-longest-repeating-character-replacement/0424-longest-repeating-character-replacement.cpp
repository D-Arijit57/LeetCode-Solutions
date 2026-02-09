class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>freq(26,0);
        int left = 0 , maxLen = 0, maxFreq = 0;
        for(int right = 0 ; right < n ; right++){
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq,freq[s[right] - 'A']);
            while((right - left + 1) - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};