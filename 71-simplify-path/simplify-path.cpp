class Solution {
public:
    string simplifyPath(string path) {
        // build the token -> directory name, push them in the stack
        // build the clean path
      int n = path.size();
      // the stack represents the current directory path
      stack<string>st;
      string ans = "",  token = "";
      for(int i = 0 ; i < n ; i++){
        // build the token
        if(path[i] != '/') token += path[i];
        // . means the current repository
        // but we have to check if the next one is . or not 
        // as that changes the decision, because that means the prev directory
        // so we cannot directly add the next one
        else {
            
        if(token == "" || token == ".") {
            // don't forget to clear the token since we don't want to carry forward this .
            token.clear();
            continue;
        } 

        // .. -> represents the previous directory : bin/usr/doc/.. -> go back to usr
        // remove the previous directory from the stack
        // if the stack isn't empty 
        // to go back to the parent directory 
        if(token == ".."){
            if(!st.empty()) st.pop();
            // also clear the token since .. doesn't represent a dir name
            // and we don't want to carry forward this .. with the actual dir name
            token.clear();
        } 

        // '/' marks the end and the start of a new directory
        // edge case for a path /a/b/c : c never gets processed since there is no ending '/'
        // directing that c should get processed 
        // so we should push c explicitly after the loop ends
        else {
             st.push(token);
             token.clear();
            } 
        }
      }
      // after a loop finishes if token isn't empty means that we have a remaining token
      // that couldn't get process because there is no ending '/' after last dir name
      // which the indicator of a complete dir name
      // so push it explicitly after the loop
      if(token != "") {
        if(token == ".") token.clear();
        else if(token == ".."){
            if(!st.empty()) st.pop();
            token.clear();
        }
        else {
            st.push(token);
            token.clear();
        }
      }

      // now we have all the directory names
      // build the clean part according to the rules
        vector<string>dirs;
        while(!st.empty()){
            string s = st.top();
            dirs.push_back(s);
            st.pop();
        }
      // build the path with the finalized dirs 
        for(int i = dirs.size() - 1; i >= 0 ; i--){
            ans += "/" + dirs[i];
        }

     return ans.empty() ? "/" : ans;
    }
};