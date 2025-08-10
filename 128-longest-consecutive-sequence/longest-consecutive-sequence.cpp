class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if (nums.empty()) return 0;
        unordered_set<int>numSet(nums.begin() ,nums.end());
        // Creat a hashset to store all numbers for O(1) lookup
        int maxLen = 0;
        // itereate through each number 
        for(int num : numSet){
            // check if this number can be the start of a sequence 
            // if left neighbour (num - 1) exists , this is not the start 
            if(numSet.find(num - 1) == numSet.end()){
                int currNum = num;
                int currLen = 1;

                // count consecutive numbers starting from this point
                while(numSet.find(currNum + 1) != numSet.end()){
                    // this is the start  of a potential sequence 
                    currNum ++;
                    currLen++;
                }
                // update maximum length found so far 
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};