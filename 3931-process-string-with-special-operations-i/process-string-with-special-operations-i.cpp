class Solution {
public:
    string processStr(string s) {
        string newStr = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (!newStr.empty()) {
                    newStr += newStr;
                }
            } else if (s[i] == '%') {
                reverse(newStr.begin(), newStr.end());
            } else if (s[i] == '*') {
                if (!newStr.empty()) {
                    newStr.pop_back();
                }
            } else {
                newStr += s[i];
            }
        }
        return newStr;
    }
};