class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        for(char c : num){
            // each upcoming digit can be added to the previous sequence
            // or it could cancel a certain number of digits and then added to the sequence
            while(!st.empty() && st.top() > c){
                // we can only remove k times
                if(k > 0){
                    st.pop();
                    k--;
                } 
                else{
                    break;
                }
            }
            // after removing push the new digit
            st.push(c);
        }
        // if the seuence of the digit is sorted
        // e.g something like 12345
        // remove from the last, since the leftmost digit is the most 
        // significant digit
        // if count stays the same means that we never popped 
        // its a sorted sequence
        while(k > 0){
            st.pop();
            k--;
        }
        // re-build the string
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        // skip the leading zeros
        int m = ans.size();
        int i = 0;
        while(i < m && ans[i] == '0'){
            i++;
        }
        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};