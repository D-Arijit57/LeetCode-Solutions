class Solution {
    /*
    Key Insight : for the ith temperature if we can find a jth temperature 
    while iterating from left to right such that ,
    j > i (means future day)
    temperatures[j] > temperatures[i] (warmer day)
    we can say we got solution for all the previous days 
    we can just find the days required by subtracting the (current day - prev day)


    we are going to store the indices (days) in the stack and whenever a warmer day in future comes 
    then we are going to find the difference between the current day and the previous days for the answers 
    */
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>ind ; // to store the indices 
        vector<int>res(n,0); // to store the results for each day 

        for(int i = 0 ; i < n ; i++){
            // for the next warmer day it solves the problem for all previous days 
            while(!ind.empty() && temperatures[i] > temperatures[ind.top()]){
                int prev = ind.top();
                ind.pop(); // make sures each day is solved exactly once 
                res[prev] = i - prev;
            }
            ind.push(i);
        }
        return res;
    }
};