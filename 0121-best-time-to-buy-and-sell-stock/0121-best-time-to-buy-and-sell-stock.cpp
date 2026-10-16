class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bestDay = INT_MAX, maxProfit = 0;
        for(int i = 0 ; i < n ; i++){
            bestDay = min(bestDay, prices[i]);
            maxProfit = max(maxProfit, abs(bestDay - prices[i]));
        }
        return maxProfit;
    }
};