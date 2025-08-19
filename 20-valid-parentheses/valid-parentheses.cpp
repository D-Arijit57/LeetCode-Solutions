class Solution {
public:
    bool isValid(string s) {
      stack<char>st;
      if(s[0] == ')' || s[0] == ']' || s[0] == '}')
      return false;
      for(int i = 0 ;  i<s.size() ; i++){
          if(s[i] == '(' || s[i] == '[' || s[i] == '{')
          st.push(s[i]);
          else if(st.size()){
              char c = st.top();
              if(c == '(' && s[i] != ')')
              return false;
              else if(c=='[' && s[i]!=']')
              return false;
              else if(c == '{' && s[i] != '}')
              return false;
              st.pop();
          }
          else
          return false;
      }
      if(!st.empty())
          return false;
        return true ;

       
    }
};