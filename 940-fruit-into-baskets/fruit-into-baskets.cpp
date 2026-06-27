class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int>freq;
        int left = 0 ;
        int maxFruits = INT_MIN;
        for(int right = 0 ; right < n ; right++){
            freq[fruits[right]]++;

            // shrink the if the window is invalid
            while(freq.size() > 2){
                freq[fruits[left]]--;
                // if the count becomes zero
                // remove it from the map
                if(freq[fruits[left]] == 0 ) freq.erase(fruits[left]);
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }
    return maxFruits;
    }
};