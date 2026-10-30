class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.length();

        int start = 0;

        int maxLen = 1;

        // Expand around every possible center

        for (int i = 0; i < n; i++) {

            // Case 1: Odd-length palindrome (e.g. "aba")

            int left = i, right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {

                if (right - left + 1 > maxLen) {

                    start = left;

                    maxLen = right - left + 1;

                }

                left--;

                right++;

            }

            // Case 2: Even-length palindrome (e.g. "abba")

            left = i;

            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {

                if (right - left + 1 > maxLen) {

                    start = left;

                    maxLen = right - left + 1;

                }

                left--;

                right++;

            }

        }

        // Extract the longest palindrome

        return s.substr(start, maxLen);
    }
};