class Solution {
public:
    bool isValid(string s) {
        // each incoming character can be a pair of the top or start of a new
        // pair at the end if its valid then stack will be empty for each
        // correct pair pop the top otherwise push it
        unordered_map<char, char> pairs = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            // each incoming element can only cancel out a single element
            // if its the pair of the top then pop it
            if (!st.empty() && s[i] == pairs[st.top()]) {
                st.pop();
            }
            // if its not a pair of the top then push it
            else st.push(s[i]);
        }
        return st.empty();
    }
};