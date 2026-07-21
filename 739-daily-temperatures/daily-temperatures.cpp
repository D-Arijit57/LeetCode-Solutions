class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Each incoming element resolves zero or more previously unresolved elements. The stack stores exactly those unresolved candidates.
        int n = temperatures.size();
        // since want distance
        // we need the indices
        stack<int>st;
        vector<int>ans(n,0);
        for(int i = 0 ; i < n; i++){

            // pop - whenever you find a greater temperature than the top
            // each incoming element can pop out multiple characters 
            // so we need a while
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                // The current day is the next warmer day for the index on top.
                // Distance = current index - previous day's index.
                // and since we are resolving it for the last warmth day
                // use the st.top() -> index
                ans[st.top()] = i - st.top();
                st.pop();
            }
            // push the new warmth day into the stack
            st.push(i);
        }
        return ans;
    }
};