class Solution {
public:
    int firstUniqChar(string s) {
        // non-repeating character means frequency is 1
        // store the frequency
        // unordered_map does not preserve the order of the characters,
        // so we iterate over the original string to find the first character
        // whose frequency is 1.
        int n = s.size();
        unordered_map<char, int> freq;
        // store the frequency
        // leetcode {key :  val} -> {character , frequency}
        // {l : 1}
        for (char c : s) {
            freq[c]++;
        }
        // since we are using a unordered_map, iterating over the map won't work
        // starting from the left and find the character with frequency == 1
        // so we'll iterate over the string from left to right and compare each
        // character's frequency
        for (int i = 0; i < n; i++) {
            if (freq[s[i]] == 1)
                return i;
        }
        // if there isn't any non repeating character
        // then return -1
        return -1;
    }
};