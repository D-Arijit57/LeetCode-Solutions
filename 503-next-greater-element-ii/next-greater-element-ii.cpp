class Solution {
public:
    vector<int> nextGreaterElements(vector<int>&nums) {
        // instead of simulating the next
        // and circling around the array physically
        // we can pretend that the array is 121121 instead of being 121
        int n = nums.size();
        stack<int>st;
        st.push(0);
        // since we are checking the positions
        // we need the indices 
        int prev = st.top();
        // no need to handle the cases where don't have a next greater element
        // so by default store -1 for it
        // the ones who next greater doesn't exist will remain -1 
        vector<int>ans(n,-1);
        
        // iteration
        for(int i = 1 ; i < 2*n ; i++){
            // pop the prev element if you found a larger one 
            // that's the next greater element
            // and the previous one is useless
            while(!st.empty() && nums[st.top()] < nums[i % n]){
                // the popped element got its answer
                // the next greater element
                // so set the prev in the top 
                // pop it up and store the next greater element at its index
                prev = st.top();
                st.pop();
                ans[prev] = nums[i%n];
            }
            // avoid pushing duplicating indices in the second pass
            if(i < n ) st.push(i);
        }
        return ans;
    }
};