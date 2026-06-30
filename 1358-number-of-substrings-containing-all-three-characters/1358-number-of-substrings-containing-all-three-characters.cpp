class Solution {
public:
    int numberOfSubstrings(string s) {
        // at least one character should be there
        // frequency map size == 3
        // once it is equal then find shrink it down to find the other
        // substrings about counting : each valid window doesn't contribute to a
        // single substring there would multiple substrings which are valid for
        // example, if the substring in the window is abca valid substrings are
        // abca,bca

        // for the counting we won't count the substrings inside the window
        // as it might lead to count of duplicate strings 
        // rather we would partition the valid strings based the left boundary
        // for example since we know that if [l...r] is valid, then it'll be valid r+n
        // so we would count all the valid substrings starting from left to right and n-1
        // e.g - abcabc, left = 0, right = 3, cnt += n - right
        // it counts abca, abcab, abcabc
        int n = s.size();
        unordered_map<int, int> freq;
        int left = 0, cnt = 0;
        for (int right = 0; right < n; right++) {
            freq[s[right]]++;

            // shrink the window
            // the key observation is
            // once the window becomes valid [l ... r]
            // r+1,r+2....r+n is also valid because we have already satisfied
            // the required frequency so irrespective of the characters in the
            // future our substring will be valid so right now to find out the
            // current valid substrings we need to do Number of valid substrings
            // starting at 'left'
            // = all possible endings from 'right' to 'n-1'
            // = n - right
            while (freq.size() == 3) {
                // Count valid substrings starting at 'left'.
                // Since [left...right] is already valid, every extension
                // of this window is also valid. The possible ending indices
                // are right, right+1, ..., n-1, giving (n - right) substrings.
                cnt += n - right;
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }
        }
        return cnt;
    }
};