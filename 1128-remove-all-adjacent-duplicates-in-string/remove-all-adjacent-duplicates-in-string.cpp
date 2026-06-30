class Solution {
public:
    string removeDuplicates(string s) {
        // The stack stores the current string after all removals.
        // If the current character matches the last kept character,
        // they form an adjacent duplicate pair, so remove the top.
        stack<char> st;
        string ans = "";
        for (char c : s) {
            // Remove exactly one adjacent pair.
            // do won't use a while it'll keep popping
            // we are doing it for a pair so. a single 'if' is enough
            if (!st.empty() && st.top() == c) {
                st.pop();
            }
            // otherwise push the character
            else
                st.push(c);
        }
        // build the string from the stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        // since its reverse order because of stack
        // reverse it again
        reverse(ans.begin(), ans.end());
        return ans;
    }
};