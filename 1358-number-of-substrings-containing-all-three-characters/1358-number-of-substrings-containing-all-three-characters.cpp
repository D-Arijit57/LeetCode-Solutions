class Solution {
public:
    int numberOfSubstrings(string s) {
      // at least one character should be there
      // frequency map size == 3
      // once it is equal then find shrink it down to find the other substrings
      // about counting : each valid window doesn't contribute to a single substring 
      // there would multiple substrings which are valid
      // for example, if the substring in the window is abca
      // valid substrings are abca,bca
      int n = s.size();
      unordered_map<int,int>freq;
      int left = 0 , cnt = 0;
      for(int right = 0 ; right < n ; right++){
        freq[s[right]]++;

        // shrink the window
        while(freq.size() == 3){
            cnt += n - right;
            freq[s[left]]--;
            if(freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
      }
        return cnt;
    }   
};