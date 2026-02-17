class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>windowFreq(26,0);
        vector<int>targetFreq(26,0);
        int n = s1.size(), m = s2.size();
        if(m < n) return false;
        // setting up the frequency for the s1 
        for(char c : s1){
            targetFreq[c - 'a']++;
        }
        // setting up the frequency for the first window
        for(int i = 0 ; i < n ; i++){
            windowFreq[s2[i] - 'a']++;
        }
        int matches = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(targetFreq[i] == windowFreq[i]) matches++;
        }
        if(matches == 26) return true;
        // sliding window approach
        for(int i = n ; i < m ; i++){
            int right = s2[i] - 'a';
            int left = s2[i - n] - 'a';

            // expanding the window 
            if(targetFreq[right] == windowFreq[right]) matches--;
            windowFreq[right]++;
            if(targetFreq[right] == windowFreq[right]) matches++;

            // shrinking the window
            if(targetFreq[left] == windowFreq[left]) matches--;
            windowFreq[left]--;
            if(targetFreq[left] == windowFreq[left]) matches++;

            if(matches == 26) return true;
        }
        return false;
    }
};