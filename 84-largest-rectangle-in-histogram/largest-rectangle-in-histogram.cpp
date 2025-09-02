class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      stack<int>st;
      int n = heights.size();
      int maxArea = 0;
      for(int i = 0 ; i < n ; i++){
        while(!st.empty() && heights[st.top()] > heights[i]){
            int topInd = st.top();
            st.pop();
            int height = heights[topInd];
            int width = st.empty() ? i : i - st.top() - 1;
            int area = height * width ;
            maxArea = max(area, maxArea);
        }
        st.push(i);
      }   
      while(!st.empty()){
         int topInd = st.top();
         st.pop();
         int height = heights[topInd];
            int width = st.empty() ? n : n - st.top() - 1;
            int area = height * width ;
            maxArea = max(area, maxArea);
      }
      return maxArea;
    }
};