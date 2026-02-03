class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freqP(26,0); // frequency of the characters in the given string p
        vector<int>freqW(26,0); // frequency of the characters in the current window
        vector<int>ans;
        int k = p.size();
        int n = s.size();
        if(k > n) return ans;
        for(char c : p){
            freqP[c - 'a']++;
        }
        for(int i = 0 ; i < k ; i++){
            freqW[s[i] - 'a']++;
        }
        // check for matches
        // we are itrating over 26 values (26 alphabets)
        // we are checking both of the arrays has the count of same characters 
        // e.g freqP[b] =1 , freqW[b] = 1 then matches++
        // e.g freqP[b] =1 , freqW[b] = 2 then matches--
        int matches = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(freqP[i] == freqW[i]) matches++;
        }
        // checking the first window
        if(matches == 26){
            ans.push_back(0);
        }
        // sliding window approach 
        for(int i = k ; i < n ; i++){
            int right = s[i] - 'a';
            int left = s[i- k] - 'a';
            // Add right characters 
            if(freqP[right] == freqW[right]) matches--;
            freqW[right]++;
            if(freqP[right] == freqW[right]) matches++;
            // Remove left characters
            if(freqP[left] == freqW[left]) matches--;
            freqW[left]--;
            if(freqP[left] == freqW[left]) matches++;

            if(matches == 26){
                ans.push_back(i - k + 1);
            }
        }
        return ans;
    }
};