class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // invariant : if the maximum frequency in the window is <= 1 throughout the algorithm
        int n = s.size();
        unordered_map<char, int>freq;
        int left = 0, maxFreq = 0, ans = 0;
        for(int right = 0 ; right < n ; right++){
            // expand the window
            freq[s[right]]++;   

            // shrink the invalid window
            // when the maximum frequency in the window is more than 1
            while(freq[s[right]] > 1){
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }

            // update the length for all the valid windows
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};