class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        // to keep a track of left 1's and right 1's 
        vector<int>leftOnes(n,0);
        vector<int>rightOnes(n,0);
        // cnt and store the most frequent 1's in the left
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1) {
                cnt ++;
            }
            else {
                cnt = 0;
            }
            leftOnes[i] = cnt ;
        }
        // reset the cnt before counting the right ones 
        cnt = 0;
        // cnt and store the most frequenet 1's in the right
        for(int i = n - 1 ;i >=0 ;i--){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            rightOnes[i] = cnt;
        }
        // define the max length of the subarray 
        int maxlen = 0;
        for(int i = 0  ; i < n ; i++){
            // for the leftcnt we are checking the count in the left side just before the position i (i.e i-1)
            // for the rightcnt we are checking the count in the right side just after the position i(i.e i+1)
            // the total length would be rightcnt + leftcnt
            int leftcnt = (i > 0 ) ? leftOnes[i-1] : 0;
            int rightcnt = ( i < n - 1 ) ? rightOnes[i+1] : 0;
            maxlen = max(maxlen, rightcnt + leftcnt);
        }
        return maxlen;
    }
};