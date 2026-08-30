class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // edge case : if the string is empty
        if(s.empty()) return 0;
        // abcabcbb
        // {a : 1, b : 1, c : 1}
        // {a :2 , b: 1, c: 1} // -> a is getting duplicated 
        // shrink the window
        // valid window : where every character as at most the fequency as one its either 0 or 1 
        int n = s.size();
        unordered_map<char, int>freq;
        int left = 0;
        int ans = INT_MIN;
        for(int right = 0; right < n ; right++){
            freq[s[right]]++;

            // shrink invalid window : where the incoming character, increases a character's frequency to more than 1
            // valid freq[right] <= 1
            while(freq[s[right]] > 1){
                // shrink from the left to maintain the contigious property
                freq[s[left]]--;
                left++;
            }
            // for every valid window update the length of the substring
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};