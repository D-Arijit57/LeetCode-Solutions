class Solution {
public:
    int characterReplacement(string s, int k) {
        //  WHY STALE MAXFREQ DOESN'T MAKE THE ANSWER GO WRONG  
        //Since we've already observed a frequency of maxFreq, 
        // we know such a strong character concentration existed at some point. We can safely use that historical best as a certificate.
        // It may delay shrinking and temporarily keep invalid windows,
        // but it cannot cause us to miss the optimal answer or report a length that was never achievable.


        // It's a valid window if requirement for replacement is less or equal to k 
        // requirement = windowsize - maxFreq (inside the frequency map)
        int n = s.size();
        // since the string only contains uppercase characters
        vector<int>freq(26,0);
        int left = 0, maxFreq = INT_MIN, maxlen = -1;
        for(int right = 0 ; right < n ; right++){
            freq[s[right] - 'A']++;
            // keep updating the max freq after every updation
            maxFreq = max(maxFreq,freq[s[right] - 'A']);
            // shrinking logic
            while((right- left + 1) - maxFreq > k){
                   freq[s[left] - 'A']--;
                   left++;             
            }
            maxlen = max(maxlen, right - left + 1);          
        }
        return maxlen == -1 ? -1 : maxlen;
    }
};