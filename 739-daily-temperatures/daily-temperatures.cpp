class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
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
                // we need to store the distance in the array before popping it out
                // distance = currentWarmthDayIndex - lastWarmthdayIndex
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