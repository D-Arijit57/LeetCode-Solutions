// parse , process, build the string
class Solution {
public:
    string simplifyPath(string path) {
        // The stack stores the directories that belong to the simplified path after processing the current path prefix.
        // atomic unit of this problem - directory 
        // each incoming element can be '/','.' or a character 
        // each element can add up to string or cancel 1 or more than 1 elements depending on the top of the stack which element it is
        // stack will represent the simplified path 
        // after the operation we can derive the simplified path 
        // simulation problem
        int n = path.size();
        string simplified_path = "";
        stack<string>st; // stores directory
        // home , foo, documents instead h o m e , f o o
        // so use a string
        string token = ""; 
        for(int i = 0 ; i <= n ; i++){
          // either we have reached the end or we have found '/'
          if(i == path.size() || path[i] == '/'){
            // process the completed token
                if(token.empty() || token == "."){
                    // ignore, do not do anything
                    // . represents the current directory 
                }
            else if(token == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            // we have a complete directory name
            // push it in the stack
            else{
                st.push(token);
            }
            token.clear();
          }
          else{
            // build the current directory name
            token += path[i];
          }
          
        }
        // rebuild the string from the stack
        vector<string>directories;
        while(!st.empty()){
            directories.push_back(st.top());
            st.pop();
        }
        reverse(directories.begin(), directories.end());

        // build the simplified path, directories separated by a path
        for(const string &str : directories){
            simplified_path += "/";
            simplified_path += str;
        }

        return simplified_path.empty() ? "/" : simplified_path;
    }
};