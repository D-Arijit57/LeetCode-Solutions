class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[n - 1] < target) return n;
        // we're looking for the element that is greater than or equal to the target
        // finding the closest to the target won't work here because if the difference is the same 
        // we don't have any parameters to determine where it should be inserted
        // [0 ... low-1] < target
        // [low ... high]    Unknown
        // [high+1 ... n-1]  >= target
        // so we need the index exactly high+1 that is the exact insert position
        // so with each iteration we make sure we eliminate the unknown space to find out the high + 1 index
        // why we do ? high = mid - 1 whenever we see nums[mid] >= target
        // in this situation we just have the information that we are somewhere at the boundary where nums[mid] >= target, we don't know if its exactly high + 1 index or in simple words there might be another valid position further to the left
        // so move towards left until low and high crosses each other 
        // once they cross each other low is bound to point towards high + 1
        int low = 0, high = n - 1;
        while(low <= high){
             int mid = low + (high - low) / 2;
             // if the we have found the target we can directly return the index
             if(nums[mid] >= target) high = mid - 1;
             else low = mid + 1;
        }
        return low;
    }
};