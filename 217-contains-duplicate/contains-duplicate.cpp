class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     unordered_map<int , int>seen;
     for(int it : nums){
        if(seen[it] >= 1) return true ;
        seen[it]++;
     }
     return false;
    }
};