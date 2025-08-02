class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // Count frequency of each fruit across both baskets
        unordered_map<int, int> freq;
        for (int fruit : basket1) {
            freq[fruit]++;
        }
        for (int fruit : basket2) {
            freq[fruit]++;
        }
        
        // Check if solution is possible
        // Each fruit must appear even number of times total
        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) {
                return -1;
            }
        }
        
        // Count how many of each fruit are in basket1
        unordered_map<int, int> basket1_count;
        for (int fruit : basket1) {
            basket1_count[fruit]++;
        }
        
        // Find fruits that basket1 needs to give away (has excess)
        // and fruits that basket1 needs to receive (has deficit)
        vector<int> to_give;  // fruits basket1 has too many of
        vector<int> to_receive; // fruits basket1 has too few of
        int min_fruit = INT_MAX;
        
        for (auto& [fruit, total_count] : freq) {
            int target_count = total_count / 2;
            int current_in_basket1 = basket1_count[fruit];
            
            min_fruit = min(min_fruit, fruit);
            
            if (current_in_basket1 > target_count) {
                // basket1 has excess of this fruit
                int excess = current_in_basket1 - target_count;
                for (int i = 0; i < excess; i++) {
                    to_give.push_back(fruit);
                }
            } else if (current_in_basket1 < target_count) {
                // basket1 has deficit of this fruit
                int deficit = target_count - current_in_basket1;
                for (int i = 0; i < deficit; i++) {
                    to_receive.push_back(fruit);
                }
            }
        }
        
        // Sort to optimize pairing
        // For to_give: sort ascending (give away cheapest first when possible)
        // For to_receive: sort descending (receive most expensive first when possible)
        sort(to_give.begin(), to_give.end());
        sort(to_receive.begin(), to_receive.end(), greater<int>());
        
        long long total_cost = 0;
        
        // Pair each fruit to give with each fruit to receive
        for (int i = 0; i < to_give.size(); i++) {
            int give_fruit = to_give[i];
            int receive_fruit = to_receive[i];
            
            // Option 1: Direct swap between baskets
            // Cost is minimum of the two fruits being swapped
            long long direct_cost = min(give_fruit, receive_fruit);
            
            // Option 2: Use minimum fruit as intermediary
            // Swap give_fruit with min_fruit, then swap min_fruit with receive_fruit
            long long indirect_cost = 2LL * min_fruit;
            
            // Choose the cheaper option
            total_cost += min(direct_cost, indirect_cost);
        }
        
        return total_cost;
    }
};