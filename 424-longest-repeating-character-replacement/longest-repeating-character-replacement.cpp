class Solution {
public:
    int characterReplacement(string s, int k) {
        // instead of simulating the operations we need to check 
        // if we can maintain a valid window with <= k operations
        // valid window -> window - maxFreq <= k
        // We need at most k replacements to make all chars equal.
        int n = s.size();
        vector<int>freq(26,0);
        int left = 0 , maxLen = 0, maxFreq = 0;
        for(int right = 0 ; right < n ; right++){
            // update the frequency of the character in the window
            freq[s[right] - 'A']++;
            // update the maxFreq (character with the maximum freq) in the window 
            maxFreq = max(maxFreq,freq[s[right] - 'A']);
            // while its not a valid window
            // shrink the window until it becomes valid again 
            while((right - left + 1) - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            // update the max length for every valid window
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};