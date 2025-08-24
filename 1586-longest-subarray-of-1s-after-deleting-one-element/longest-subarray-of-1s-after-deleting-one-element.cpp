class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        // to keep a track of left 1's and right 1's 
        vector<int>leftOnes(n,0);
        vector<int>rightOnes(n,0);

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
        cnt = 0;
        for(int i = n - 1 ;i >=0 ;i--){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            rightOnes[i] = cnt;
        }

        int maxlen = 0;
        for(int i = 0  ; i < n ; i++){
            int leftcnt = (i > 0 ) ? leftOnes[i-1] : 0;
            int rightcnt = ( i < n - 1 ) ? rightOnes[i+1] : 0;
            maxlen = max(maxlen, rightcnt + leftcnt);
        }
        return maxlen;
    }
};