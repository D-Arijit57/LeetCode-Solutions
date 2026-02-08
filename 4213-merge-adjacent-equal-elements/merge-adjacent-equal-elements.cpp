class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>copy(nums.begin(),nums.end());
        vector<long long>st;

        for(auto it : copy){
            while(!st.empty() && it == st.back()){
                    it = st.back() + it;
                    st.pop_back();
            }
        st.push_back(it);
        }
        return st ;
    }
};