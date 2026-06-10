class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<int, int>mp;
      mp[0] = -1; 
      int prefix = 0, rem = 0;
      for(int i = 0 ; i < n ; i++){
        prefix += nums[i];
        // calculate the remainder
        rem = prefix % k;

        // if you already found somewhere means the multiple exist
        if(mp.count(rem)) {
            // check the sub-array length if its atleast 2 
            int prevInd = mp[rem]; // gives the index it occured at first 
            if(i - prevInd >= 2) return true;
        }
        // update the remainder frequency
       else mp[rem] = i;
      }
      return false;
    }
};