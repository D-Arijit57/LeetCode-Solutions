class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;

        unordered_map<char, int>countFreq;
        
        int left = 0, ans = 0;

        for(int right = 0 ; right < n ; right++){
            countFreq[s[right]]++;

            while(countFreq[s[right]] > 1){
                countFreq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;

    }
};