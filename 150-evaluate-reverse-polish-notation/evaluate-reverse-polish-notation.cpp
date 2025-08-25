class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
            if(tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "-"){
                int elem1 = st.top();st.pop();
                int elem2 = st.top();st.pop();
                int ans = 0;
                if(tokens[i] == "+"){
                    ans += elem2 + elem1;
                    st.push(ans);
                }
                else if(tokens[i] == "/"){
                    ans += elem2 / elem1;
                    st.push(ans);
                }
                else if(tokens[i] == "*"){
                    ans += elem2 * elem1;
                    st.push(ans);
                }
                else {
                    ans += elem2 - elem1;
                    st.push(ans);
                }
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};