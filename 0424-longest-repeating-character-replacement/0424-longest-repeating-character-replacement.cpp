class Solution {
public:
    int characterReplacement(string s, int k) {
        // invariant : requirement <= k
        // if requiremnet > k shrink the window because that's a invalid one
        int n = s.size();
        int left = 0;
        unordered_map<char, int>freq;
        int ans = INT_MIN, maxFreq = 0;
        for(int right = 0 ; right < n  ; right++){
            // expand the window
            freq[s[right]]++;
            // shrink the invalid window 
            // requirement = windowSize - frequency of the most frequent character
            maxFreq = max(maxFreq, freq[s[right]]);
            while((right - left + 1) - maxFreq > k){
                freq[s[left]]--;
                left++;
            }
            // update longest length
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};