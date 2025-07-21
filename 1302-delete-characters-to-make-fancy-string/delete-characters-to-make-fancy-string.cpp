class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) {
            return s; // Can't have 3 consecutive characters
        }
        
        string result;
        result.push_back(s[0]); // Add first character
        
        int count = 1; // Count of consecutive identical characters
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                count++;
                // Only add if we haven't reached 2 consecutive yet
                if (count < 3) {
                    result.push_back(s[i]);
                }
                // If count >= 3, skip this character
            } else {
                // Different character, reset count and add it
                count = 1;
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};