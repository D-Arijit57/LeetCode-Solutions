class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       // sliding window approach
       // the invariant here is the maximum frequency of each element should stay <= k
       // so we would check each time it we expand the window to include the new element
       // the moment the freq[right] > k we shrink the window
       int n = nums.size();
       unordered_map<int,int>freq;
       int left = 0;
       int ans = INT_MIN;
       for(int right = 0 ; right < n ; right++){
            // expand the window
            freq[nums[right]]++;

            // shrink the window
           
            while(freq[nums[right]] > k){
                // we don't remove the frequency of the element who violated the condition 
                // because it would break the contigious window
                // the reason it still correctly detects the invalid window because
                // even after removing the elements which didn't violate the condition 
                // eventually it'll reach the element that violated the condition
                freq[nums[left]]--;
                left++;
            }

            // update max length for each valid window
            ans = max(ans, right - left + 1);
       }
       return ans;
    }
};