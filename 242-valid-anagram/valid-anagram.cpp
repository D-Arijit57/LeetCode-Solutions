class Solution {
public:
    bool isAnagram(string s, string t) {
     if (s.size() != t.size()) return false ;
     unordered_map<char,int>mpp;
     for(int i = 0 ; i < s.size() ; i++){
        mpp[s[i]]++;
     }
     for(char ch : t){ // itereate in the other string 
        // for each character in the second string 
        // if you do not find the character in the map
        // or else of the count of that specific character is 0 in the map
        // then you should return false
        if(mpp.find(ch) == mpp.end()|| mpp[ch] == 0) return false;

        // if you do find the the character in the map
        // just make sure you cancel out the frequency of that character 
        // e.g : carrace, racecar -> in this case we have two r's we each time we find r we cancel it out (frequency) by the times of the frequency in the other string 
        mpp[ch]--;
     }
     return true ;
    }
};