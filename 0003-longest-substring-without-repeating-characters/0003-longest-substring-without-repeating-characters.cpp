class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if the frequency in the current window gets more than 1 
        // it's a invalid window 
        // the frequency of any character inside the window should be <= 1
        int n = s.size();
        int left = 0 ;
        unordered_map<char, int>freq;
        int ans = 0;
        for(int right = 0 ; right < n ; right++){
            freq[s[right]]++;

            while(freq[s[right]] > 1){
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};