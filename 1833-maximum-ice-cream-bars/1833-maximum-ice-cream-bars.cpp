class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // greedy algorithm
        // track the cost that is beneficial 
        // lower the cost , more the icecreams
        // we can sort out the ice creams since the boy can choose in any order

        sort(costs.begin(),costs.end());
        int n = costs.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(costs[i] > coins) break;
            coins -= costs[i];
            cnt++;
            
        }
        return cnt;
        
    }
};