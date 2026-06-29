class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // in the stack each element should represent the indices
        // since we need the distances between the last and next warmth day
        // invariant : temperatures[prev] > temperatures[current]
        // if we find a temperature that is warmer than the previous
        // the previous one becomes useless
        int n = temperatures.size();
        stack<int>st;
        st.push(0);
        vector<int>ans(n, 0);
        int lastIndex = st.top();
        for(int i = 1 ; i < n ; i++){
            int current  = temperatures[i];
            // st.top() < current -> next warmth day
            // pop out the ones violating the invariant
            while(!st.empty() && temperatures[st.top()] < current){
                lastIndex = st.top();
                st.pop();
                // we are finding out the warmth day after lastIndex
                // so store the next warmth day at lastIndex 
                // distance = currentIndex - lastIndex
                ans[lastIndex] = i - lastIndex;
            }
            st.push(i);
        }
        return ans;
    }
};