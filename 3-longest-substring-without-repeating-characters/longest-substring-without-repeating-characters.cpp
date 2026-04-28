class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int>freq;
        int left = 0, maxLen = 0;
        for(int right = 0 ; right < n ; right++){
            freq[s[right]]++;

            // check if the current character already exists in the window
            if(freq[s[right]] > 1){

                // if it does we need to shrink the window till the duplicate gets removed
                while(freq[s[right]] > 1){
                    freq[s[left]]--;
                    // in case it becomes zero, remove it from the map
                    if(freq[s[left]] == 0) freq.erase(s[left]);
                    left++;
                }
            }
            // shrinking logic
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};