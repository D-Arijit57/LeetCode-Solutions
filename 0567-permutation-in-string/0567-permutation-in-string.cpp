class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        vector<int>windowFreq(26,0);
        vector<int>targetFreq(26,0);
        // update both of the windows
        for(int i = 0  ; i < n ; i++){
            windowFreq[s2[i] - 'a']++;
            targetFreq[s1[i] - 'a']++;
        }
        int matches = 0;
        // check for the first window
        for(int i = 0 ; i < 26 ; i++){
            if(windowFreq[i] == targetFreq[i]) matches++;
        }
        if(matches == 26) return true;
        
        // checking for the rest of the window
        for(int i = n ; i < m ; i++){
            int right = s2[i] - 'a';
            int left = s2[i - n] - 'a';

            // update when adding new character
            if(windowFreq[right] == targetFreq[right]) matches--;
            windowFreq[right]++;
            if(windowFreq[right] == targetFreq[right]) matches++;
        
            // update when removing the old character 
            if(windowFreq[left] == targetFreq[left]) matches--;
            windowFreq[left]--;
            if(windowFreq[left] == targetFreq[left]) matches++;

            if(matches == 26 ) return true;
        }
        return false;
    }
};