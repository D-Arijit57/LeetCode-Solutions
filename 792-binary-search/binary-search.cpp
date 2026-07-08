class Solution {
public:
    int search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        // eliminate the search space
        int n = nums.size();
        int low = 0 , high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // eliminate the right search space
            if(nums[mid] > target) high--;
            // eliminate the left search space 
            else if(nums[mid] < target) low++;
            else return mid;
        }
        return -1;
    }
};