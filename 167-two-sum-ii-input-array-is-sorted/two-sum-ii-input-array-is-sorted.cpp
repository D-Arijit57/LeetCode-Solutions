class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0 , right = n - 1;
        while(left <= right){
            if(numbers[left] + numbers[right] == target) return {left + 1, right + 1};
            else if(numbers[left] + numbers[right] < target) left++;
            else right --;
        }
        return {-1,-1};
    }
};