class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n = nums.size();
       vector<int>prefix(n+1,0);
       // to store the values in the prefix array 
       for(int i = 0; i < n ; i++){
            prefix[i+1] = prefix[i] + nums[i];
       } 
       // now at each index check if left sum == right sum
       int left_sum = 0, right_sum = 0;
       for(int i = 0 ; i < n; i++){
            left_sum = prefix[i];
            right_sum = prefix[n] - prefix[i+1];
            if(left_sum == right_sum) return i;
       }
       return -1;
    }
};