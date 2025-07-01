class Solution {
public:
    vector<string> partitionString(string s) {
         unordered_map<string,int> m;
        vector<string> ans;
        ans.push_back(string(1,s[0]));
        m[string(1,s[0])]=1;

        int i=1;
        string a="";
        while(i<s.size()){
            a+=s[i];

            if(m[a]==0){
                ans.push_back(a);
                m[a]++;
                a="";   
            }

            i++;
        }
        
        return ans;
    }
};