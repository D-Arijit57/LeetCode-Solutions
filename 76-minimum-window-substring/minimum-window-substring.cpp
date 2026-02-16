class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freqT(128,0);
        vector<int>freqW(128,0);
        int n = s.size(), m = t.size();
        if(t.empty() || s.empty()) return "";
        if(m > n) return "";
        // setting up the frequencies for the string t 
        for(char c : t){
            freqT[c]++;
        }
        // required -> number of distinct characters in t
        int required = 0;
        for(int i = 0; i < 128 ; i++){
            if(freqT[i] > 0){
                required++;
            }
        }
        int formed = 0;
        // sliding window approach 
        int left = 0;
        int minLen = INT_MAX;
        int startIndex = 0;
        // expand the window 
        for(int right = 0 ; right < n ; right++){
            s[right];
            freqW[s[right]]++;

            if(freqW[s[right]] == freqT[s[right]]){
                formed++;
            }
            // we have already found one answer we need to find a smaller one 
            // since we are searching for the minimum window string 
            while(formed == required){
                // update minimum window
                int windowLen = right - left + 1;
                if(windowLen < minLen){
                    minLen = windowLen;
                    startIndex = left;
                }
                // remove the character from the left inside the window 
                freqW[s[left]]--;
                // check after removing
                if(freqW[s[left]] == freqT[s[left]] - 1){
                    formed--;
                }

                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex,minLen) ;

        

            
        
         
    }
};