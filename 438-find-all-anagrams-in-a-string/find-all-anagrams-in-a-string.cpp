class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m > n) return {};
        int matches = 0;
        vector<int>windowFreq(26,0);
        vector<int>targetFreq(26,0);
        vector<int>ans;
        // updating the target freq
        for(int i = 0 ; i < m ; i++){
            targetFreq[p[i] - 'a']++;
            windowFreq[s[i] - 'a']++;
        }

        // checking for the first window 
        for(int i = 0 ; i < 26 ; i++){
            if(windowFreq[i] == targetFreq[i]) matches++;
        }
        
        if(matches == 26) ans.push_back(0);

        // for the rest of the window
        for(int right = m ; right < n ; right++){
            int add = s[right] - 'a';
            int remove = s[right - m] - 'a';
            // transition mechanism
            // check if the count before and after the window before updating 
            if(windowFreq[add] == targetFreq[add]) matches--;
            windowFreq[add]++;
            if(windowFreq[add] == targetFreq[add]) matches++;

            // check if the count before and after window before removing a character
            if(windowFreq[remove] == targetFreq[remove]) matches--;
            windowFreq[remove]--;
            if(windowFreq[remove] == targetFreq[remove]) matches++;

            if(matches == 26 ) ans.push_back(right - m + 1);
        }
        return ans;
    }
};