class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char>sc , tc;
        for(char c : s){
            if(c >= 'a' && c <= 'z') sc.push_back(c);
            else if (c = '#' && !sc.empty()) sc.pop_back();
        }
        for(char c: t){
            if( c >= 'a' && c <= 'z') tc.push_back(c);
            else if( c = '#' && !tc.empty() ) tc.pop_back();
        }
        return sc == tc;
     }
};