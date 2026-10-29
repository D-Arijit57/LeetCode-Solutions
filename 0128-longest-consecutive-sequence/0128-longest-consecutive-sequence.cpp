class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // instead of sorting out the array
        // what we are going to do here is using a hashset 
        // we're gonna check if the consecutive numbers exist or not 
        unordered_set<int>st(nums.begin(), nums.end());

        int longest_seq = 0;

        for(int it : st){
            
            // if the number before the current number exist
            // for example :
            // if curr is 2 but 1 exists then we should skip it as a starting point
            if(st.find(it - 1) == st.end()){
                int curr = it;
                int len = 1;

            // while there the consecutive sequence continues
            while(st.find(curr + 1) != st.end()){
                curr++;
                len++;
            }
            // whenever it breaks the sequence 
            // update the longest sequence 
            longest_seq = max(longest_seq, len);
            }  
        }

        return longest_seq;
    }
};