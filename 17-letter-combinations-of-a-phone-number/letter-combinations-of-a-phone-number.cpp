 class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        return helper("", digits);
    }

    vector<string> helper(string processed, string up) {
        if (up.empty()) return {processed};

        int button = up[0] - '0';
        vector<string> ans;

        if (button >= 2 && button <= 6) {
            for (int i = (button - 2) * 3; i < (button - 1) * 3; i++) {
                char ch = 'a' + i;
                vector<string> sub = helper(processed + ch, up.substr(1));
                ans.insert(ans.end(), sub.begin(), sub.end());
            }
        } else if (button == 7) {
            for (int i = 15; i < 19; i++) {
                char ch = 'a' + i;
                vector<string> sub = helper(processed + ch, up.substr(1));
                ans.insert(ans.end(), sub.begin(), sub.end());
            }
        } else if (button == 8) {
            for (int i = 19; i < 22; i++) {
                char ch = 'a' + i;
                vector<string> sub = helper(processed + ch, up.substr(1));
                ans.insert(ans.end(), sub.begin(), sub.end());
            }
        } else if (button == 9) {
            for (int i = 22; i < 26; i++) {
                char ch = 'a' + i;
                vector<string> sub = helper(processed + ch, up.substr(1));
                ans.insert(ans.end(), sub.begin(), sub.end());
            }
        }
        return ans;
    }
};