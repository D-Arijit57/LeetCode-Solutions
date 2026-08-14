class Solution {
public:
    int maximumLengthSubstring(string s) {
        // invariant : each character inside the window must have a frequency <= 2
        // the freq[incoming_char] > 2 then we have to shrink the window from the left
       int n = s.size();
       vector<int>freq(26,0);
       int left = 0, ans = INT_MIN;
       for(int right = 0 ; right < n ; right++){
            // expand the window 
            freq[s[right] - 'a']++;

            // shrink the window 
            while(freq[s[right] - 'a'] > 2){
                freq[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
       }
       return ans;
    }
};