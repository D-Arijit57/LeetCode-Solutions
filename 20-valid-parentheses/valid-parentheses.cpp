class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> CloseToOpen = {
            {')', '('}, {'}', '{'}, {']', '['}};
        for (char c : s) {
            if (CloseToOpen.count(c)) {
                if (!st.empty() && st.top() == CloseToOpen[c]) {
                    st.pop();
                } else
                    return false;
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
    };