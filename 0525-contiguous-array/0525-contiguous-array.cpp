class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       // the main trick is thinking 0 as -1 and 1 as +1 
       // so if the subarray has equal number 0 and 1s
       // for the sum will stay 0
       int n = nums.size();
       // to store the indices where sum = 0 occured we will use a map
       unordered_map<int, int>mp;
       
       // prefixSum = 0 occured before array started
       mp[0] = -1;

       // prefix -> to keep the track of the sum
       int prefix = 0;
       int maxLen = 0;
       for(int i = 0 ; i < nums.size() ; i++){
         if(nums[i] == 0){
            prefix -= 1;
         }
         else {
            prefix += 1; 
         }

         if(mp.count(prefix)){
            maxLen = max(maxLen, i - mp[prefix]); // i - mp[prefix] -> currentIndex - firstOccurence
         }
         else mp[prefix] = i; // incase it doesn't exist then store it in the map 
       }
       
    return maxLen;
    }
};