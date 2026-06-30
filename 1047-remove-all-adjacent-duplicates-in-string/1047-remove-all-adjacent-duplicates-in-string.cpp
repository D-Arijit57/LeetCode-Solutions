class Solution {
public:
    string removeDuplicates(string s) {
        // we need to remove two adjacent and equal letters 
        // till s no longer consists the duplicate characters
        // we need to pop the element when it matches with the top
        // because it is the duplicate of the element we last saw
        // The stack will always represent the string after removing all adjacent duplicates processed so far.
        stack<char>st;
        string ans = "";
        for(char c : s){
            // Remove exactly one adjacent pair.
            // do won't use a while it'll keep popping
            // we are doing it for a pair so. a single 'if' is enough
            if(!st.empty() && st.top() == c){
                st.pop();
            }
            // otherwise push the character
            else st.push(c);
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