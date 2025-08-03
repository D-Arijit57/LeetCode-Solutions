class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;
        vector<vector<string>>ans;
        for(auto const& s : strs) {
            string key = s;
            sort(key.begin(),key.end());
            mpp[key].push_back(s);
        }
        for(auto const& pair : mpp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};