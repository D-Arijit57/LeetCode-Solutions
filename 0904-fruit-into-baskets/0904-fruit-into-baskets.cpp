class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>freq;
        int left = 0, maxLen = INT_MIN;
        for(int right = 0 ; right < n ; right++){
            freq[fruits[right]]++;

            while(freq.size() > 2){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            
            maxLen = max(maxLen,right - left + 1);
        }
        return maxLen;
    }
};