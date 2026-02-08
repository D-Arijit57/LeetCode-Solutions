class Solution {
public:
    int dominantIndices(vector<int>& nums) {
            int n = nums.size();
            int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            int sum = 0 , numOfElements = 0;
            for(int j = i + 1 ; j < n ; j++ ){
                    sum += nums[j];
                    numOfElements++;
            }
            double avg = (double)sum / numOfElements;
            if(nums[i] > avg) cnt++;
        }
        return cnt;
    }
};