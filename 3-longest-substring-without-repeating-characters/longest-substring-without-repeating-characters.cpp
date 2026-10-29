class Solution {
public:
    int lengthOfLongestSubstring(string s) {
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