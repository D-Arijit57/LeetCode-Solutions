class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        // using a stack 
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
            // if the string is an operator 
            if(tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "-"){
                // takeout the two elements 
                int elem1 = st.top();st.pop();
                int elem2 = st.top();st.pop();
                int ans = 0;
                // perform the operation according to the string 
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
            // if its a number , then push it into the stack 
            else {
                st.push(stoi(tokens[i]));
            }
        }
        // return the top of the stack since only one element is left
        return st.top();
    }
};