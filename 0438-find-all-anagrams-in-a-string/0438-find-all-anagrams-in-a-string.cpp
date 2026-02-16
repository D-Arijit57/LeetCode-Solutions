class Solution {
public: // REVISION 1 : 
    vector<int> findAnagrams(string s, string p) {
        vector<int>freqP(26,0);
        vector<int>freqW(26,0);
        vector<int>ans;
        int n = s.size(), k = p.size();
        // MISTAKE 1 :  Forgot about the edge case
        if(k > n) return ans;
        // setting up the frequency array for string p
        for(char c : p){
            freqP[c - 'a']++;
        }
        // setting up the frequency for the first window
        for(int i = 0 ; i < k ; i++){
            freqW[s[i] - 'a']++;
        }
        int matches = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(freqP[i] == freqW[i]) matches++;
        }
        if(matches == 26) ans.push_back(0);
        // sliding window for the rest of the string
        for(int i = k ; i < s.size() ; i++){
            // setting up the pointers
            int left = s[i - k] - 'a';
            int right = s[i] - 'a';

            // expanding the window 
            // check before adding the window 
            if(freqP[right] == freqW[right]) matches--;
            freqW[right]++;
            // check after adding the window 
            if(freqP[right] == freqW[right]) matches++;

            // shrinking the window
            // check before shrinking the window 
            if(freqP[left] == freqW[left]) matches--;
            freqW[left]--;
            // check after shrinking the window
            if(freqP[left] == freqW[left]) matches++;

            if(matches == 26){
                // MISTAKE 2 : instead of the right index you were pushing length using right - left + 1
                ans.push_back(i - k + 1);
            }
        }
        return ans;
    }
};