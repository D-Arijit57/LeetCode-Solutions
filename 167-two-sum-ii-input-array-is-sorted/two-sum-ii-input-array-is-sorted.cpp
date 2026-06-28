class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // since the array is sorted
        // we can use two pointers
        // the more we go towards right the larger elements we get 
        // and smaller elements if we go left
        // that way we can adjust the sum according to the target 
        // to find the answer indices
        int n = numbers.size();
        int left = 0, right = n - 1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum < target){
                left++;
            }
            else if(sum > target){
                right--;
            }
            else return {left+1,right+1};
        }
        return {-1,-1};
    }
};