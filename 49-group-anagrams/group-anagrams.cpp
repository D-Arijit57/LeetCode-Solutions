class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create a map 
        // key = > sorted version of the string 
        // value => original string (since it is a anagram itself to the sorted string)
        unordered_map<string, vector<string>>mpp;
        // ans array to return the answer 
        vector<vector<string>>ans;
        // iterate through the array of strings
        // to store the key val pair 
        for(auto const& s : strs) {
            string key = s;
            sort(key.begin(),key.end());
            mpp[key].push_back(s);
        }
        // reiterate through the map 
        // store the value (consists of all the anagrams) of the map 
        for(auto const& pair : mpp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};