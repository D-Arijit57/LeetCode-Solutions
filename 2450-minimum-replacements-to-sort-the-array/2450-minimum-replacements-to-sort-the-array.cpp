//The logic revolves around the idea of iteratively choosing the optimal replacement strategy for each element to ensure non-decreasing order while minimizing the number of operations. The division operation is used to determine how many times an element needs to be divided to fit within the constraints of non-decreasing order. This approach cleverly balances the need for replacement operations with the goal of keeping the array sorted with minimal changes.
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

       int n = nums.size();
       int last = nums[n-1];
       long long ans = 0;
       for(int i = n - 2 ; i>=0 ; i--){
           if(nums[i] > last){
               int replacetimes = nums[i] / last; // number of times the element needs replacement
               if(nums[i] % last) replacetimes++; // if there's any remainder increase the replacement times 
               last = nums[i] / replacetimes; // updating the last for the next comparison
               ans += replacetimes-1; // add (t-1) to ans for the number of operation
           }
           else{
               last = nums[i];
           }
       }
       return ans;
    }
};