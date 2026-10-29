class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // instead of sorting out the array
        // what we are going to do here is using a hashset 
        // we're gonna check if the consecutive numbers exist or not 
        unordered_set<int>st(nums.begin(), nums.end());

        int longest_seq = 0;

        for(int it : st){

            if(st.find(it - 1) == st.end()){
                int curr = it;
                int len = 1;

            while(st.find(curr + 1) != st.end()){
                curr++;
                len++;
            }

            longest_seq = max(longest_seq, len);
            }  
        }

        return longest_seq;
    }
};