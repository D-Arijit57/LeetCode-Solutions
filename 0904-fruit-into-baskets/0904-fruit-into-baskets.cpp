class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int maxCnt = 0;
        // keeping a map to update the frequencies of each type of fruit
        unordered_map<int,int>freq;
        for(int right = 0 ; right < n ; right++){
            // we use right to expand the window 
            // for each fruit (new or known) we update the frequency
            freq[fruits[right]]++;
            // since the basket size is 2 
            // if there's more than 2 types of fruit
            // we update the frequency (reduce it)
            // if any of the fruit's count become zero we remove it
            while(freq.size() > 2){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            // we update the max count for new maximum fruits 
            maxCnt = max(maxCnt, right - left + 1);
        }
        return maxCnt;
    }
};