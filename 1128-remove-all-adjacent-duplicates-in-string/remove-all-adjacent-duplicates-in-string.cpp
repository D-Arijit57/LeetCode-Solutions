class Solution {
public:
    string removeDuplicates(string s) {
        // we need to remove two adjacent and equal letters 
        // till s no longer consists the duplicate characters
        int n = s.size();
        stack<char>st;
        st.push(s[0]);
        string ans = "";
        for(int i = 1 ; i < n ; i++){
            // Remove exactly one adjacent pair.
            // do not use a while it'll keep popping
            // we are doing it for a pair so. a single 'if' is enough
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
            // otherwise push the character
            else st.push(s[i]);
        }
        // build the string from the stack
        while(!st.empty()){
           ans += st.top();
           st.pop();
        }
        // since its reverse order because of stack
        // reverse it again
        reverse(ans.begin(),ans.end());
        return ans;
    }
};