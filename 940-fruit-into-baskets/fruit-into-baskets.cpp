class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket; // fruit type -> count
        int left = 0;
        int maxFruits = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            // Add current fruit to basket
            basket[fruits[right]]++;
            
            // If we have more than 2 types of fruits, shrink window from left
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            
            // Update maximum fruits collected
            maxFruits = max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
};