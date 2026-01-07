class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0 , right = n - 1;
        while(left <= right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                // since its a one indexed array 
                return {left+1,right+1}; 
            }
            else if(sum > target){
                right--;
            }
            else{
                left++;
            }
        }
        return {-1,-1};
    }
};