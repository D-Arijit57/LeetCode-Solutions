class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int>ans;
        // place the numbers where it is supposed to be 
        while(i < n ){
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]){
                swap(nums[i],nums[correctIndex]);
            }
            else i++;
        }
        // check if the numbers in their correct position
        // if not then that index has the incorrect number
        for(int i = 0 ; i < n ; i++){
            if( i != nums[i] - 1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};