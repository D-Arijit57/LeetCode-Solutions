class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>output(nums.size() , 1); // inititalizing the output array witb 1s
        int left = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            output[i] *= left;
            left *= nums[i];  // calculating the products of the left elements
        }
        int right = 1;
        for(int i = nums.size() - 1 ; i >= 0 ; i-- ){
            output[i] *= right ;
            right *= nums[i];   // caluclating the products of the right elements 
        }
        return output;
    }
};