class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);  // Track which baskets are used
        int unplaced = 0;
        
        // Process each fruit type from left to right
        for (int i = 0; i < n; i++) {
            bool placed = false;
            
            // Find the leftmost available basket with sufficient capacity
            for (int j = 0; j < n; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;  // Mark basket as used
                    placed = true;
                    break;
                }
            }
            
            // If no suitable basket found, increment unplaced count
            if (!placed) {
                unplaced++;
            }
        }
        
        return unplaced;
    }
};