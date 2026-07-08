class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1) return 1;
        // we need characters in pairs
        // for example a string abaabacddea
        // we have 3 pairs of a , 1 pair of d and we can take either c or e 
        // that makes a palinedrome string of length 9
        // any odd one should be at the middle 
        // covering both sides from the even ones
        int n = s.size();
        unordered_map<char,int>freq;
        bool hasOdd = false; // acts as a flag if an count can give a odd contribution 
        // store the frequency of each character in the string 
        for(char c : s){
            freq[c]++;
        }
        int cnt = 0;
        // iterate the map
        // count the character with even frequency
        // check if there's any odd count 
        // then take the maximum even count + 1 odd if there's any
        for(const auto& it : freq){
            if(it.second % 2 == 1){
                hasOdd = true;
            }
            // take the maximum possible even
            cnt += it.second - (it.second % 2);
        }
        // if there's any odd that we have seen then add it up
        cnt += hasOdd ? 1 : 0;
        return cnt;
    }
};