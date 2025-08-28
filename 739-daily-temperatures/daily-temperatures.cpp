class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>ind ; // to store the indices 
        vector<int>res(n,0); // to store the results for each day 

        for(int i = 0 ; i < n ; i++){
            while(!ind.empty() && temperatures[i] > temperatures[ind.top()]){
                int prev = ind.top();
                ind.pop();
                res[prev] = i - prev;
            }
            ind.push(i);
        }
        return res;
    }
};