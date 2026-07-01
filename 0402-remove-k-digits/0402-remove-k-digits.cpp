class Solution {
public:
    string removeKdigits(string num, int k) {
        // remove the digit that gives us maximum benefit
        // Each incoming digit keeps removing larger previous digits until it can no longer improve the current prefix.
        // the digits in the left are more significant compared to the digits in the right
        // so if we iterate from left and look for smaller digits only we'll eventually have the smallest integer string after k digits removal
        int n = num.size();
        stack<char>st;
        st.push(num[0]);
        string ans = "";
        for(int i = 1 ; i < n ; i++){
            
            // remove the digit in the stack if the incoming digit is smaller compared to this 
            // 1. remove the left digits since till there are 0 removals left 
            while(!st.empty() && st.top() > num[i]){
                // we only have k removals
                // so make sure we do have available moves for the removal
                if(k == 0) break;                
                st.pop();
                k--;
                
            }
            // 2. extend the previous sequence 
            st.push(num[i]);
        }
        // if k is still greater than 0 
        // remove the digits from the right
        // because the digit are in ascending order 
        // means that the digits in the left will be eventually smaller
        if(k > 0){
            // remove the k digits from the right end
            int i = 0;
            while(i < st.size() && k--){
                st.pop();
            }

        }
        // build the string
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // remove the leading zeros in the string
        // skip the leading zeros if we say more precisely 
        int i = 0;
        while(i < ans.size() && ans[i] == '0'){
            i++;
        }
        ans = ans.substr(i);

        return ans == "" ? "0" : ans;
       
    }
};