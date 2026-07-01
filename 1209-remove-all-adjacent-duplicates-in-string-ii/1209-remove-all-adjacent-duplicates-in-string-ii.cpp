class Solution {
public:
    string removeDuplicates(string s, int k) {
        // each incoming character either extends the previous group or starts a new one
        if(s.size() <= 1) return s;
        // unlike an adjacent pair we need to store consecutive groups of each character
        // to track how many times each character appeared in the string
        // stack will store the current reduced string with the count of the consecutive group at the end
        int n = s.size();
        string ans = "";
        // stack -> (character, frequency)
        stack<pair<char,int>>st;
        st.push({s[0],1});
        for(int i = 1 ; i < n ; i++){
            // that is the top of the stack becomes equal with the current element
            // do not use while since it would update the frequency multiple times since the character will be same because of the condition
            if(!st.empty() && st.top().first == s[i]){
               // increase the frequency
               // update the frequency first since we have found it again
                st.top().second++;

               // if the count is exactly equal to k
               // pop the element
               if(st.top().second == k){
                st.pop();
               }
               
            }
            // if the incoming character doesn't extend the previous group
            // push the new group
            else st.push({s[i],1});
        }
        // rebuild the string
        while(!st.empty()){
            // make sure you remember the frequency of each character
            // do not just add them once
            ans.append(st.top().second, st.top().first);
            st.pop();
        }
        // reverse since the order is reversed in the stack
        reverse(ans.begin(),ans.end());
        return ans;
    }
};