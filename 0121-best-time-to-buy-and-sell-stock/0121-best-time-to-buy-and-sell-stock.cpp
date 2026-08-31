class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // the best profit would be lowest buying price and highest selling price
        // we maintain a min_seen variable to store the minimum price we have seen so far
        // so check the profit by finding the difference between the prices[i] - min_seen
        int n = prices.size();
        int min_seen = INT_MAX;
        int profit = 0;
        for(int i = 0 ; i < n ; i++){
            min_seen = min(min_seen, prices[i]);
            profit = max(profit, prices[i] - min_seen);
        }
        return profit;
    }
};