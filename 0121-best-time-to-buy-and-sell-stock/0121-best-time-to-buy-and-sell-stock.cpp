class Solution {
public:
    int maxProfit(vector<int>& prices) {
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