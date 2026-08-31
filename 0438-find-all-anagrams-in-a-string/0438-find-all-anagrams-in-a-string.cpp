class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       // edge case : if p is greater in length compared to s
       // its impossible for s to have all of its anagrams
       if(p.size() > s.size()) return {};

       int n = s.size();
       int m = p.size();

       vector<int>ans;
       
       // we are maintaining two frequency maps to compare 
       // the current vs desired frequency
       vector<int>windowFreq(26,0);
       vector<int>targetFreq(26,0);
        
        // load targetFreq and windowFreq with p's and s's frequency accordingly
        // so that we can check for the first window 
        for(int i = 0 ; i < m ; i++){
            targetFreq[p[i] - 'a']++;
            windowFreq[s[i] - 'a']++;
        }
        // check for the first window, for all the 26 characters 
        // if the window has the desired frequency the matches will stay 26 always
        // if there's any discrepency (< 26) means that the window's frequency is not the desired frequency
        int matches = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(targetFreq[i] == windowFreq[i]) matches++;   
        }
        if(matches == 26) ans.push_back(0);

        // now since we have checked for the first window
        // check for the entire string after the length that we just checked
        for(int i = m ; i < n ; i++){
            int left = s[i - m] - 'a';
            int right = s[i] - 'a';

            // check for the character entering the window
            if(windowFreq[right] == targetFreq[right]) matches--;
            windowFreq[right]++;
            if(windowFreq[right] == targetFreq[right]) matches++;


            // check for the character leaving the window
            if(windowFreq[left] == targetFreq[left]) matches--;
            windowFreq[left]--;
            if(windowFreq[left] == targetFreq[left]) matches++;
            
            // if only matches stays the same, then only we know 
            // the window is valid and the substring is a anagram of p
            if(matches == 26) ans.push_back(i - m + 1);
        }
        return ans;
    }
};