class Solution {
public:
 // implementing lowerbound and upperbound
int lowerbound(vector<int>&nums , int target){
    int n = nums.size();
    int ans = n , low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high) / 2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int upperbound(vector<int>&nums , int target){
    int n = nums.size();
    int ans = n , low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high) / 2;
        if(nums[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
     int lb = lowerbound(nums,target);
     int ub = upperbound(nums,target);
     int n = nums.size();
     if(lb == n|| nums[lb] != target) return {-1,-1};
     return {lb , ub-1};
    }
};