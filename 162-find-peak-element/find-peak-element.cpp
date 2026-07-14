class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    // the elimination of either of the halves depends on the mid
    // if nums[mid] < nums[mid + 1] we can see there is an increasing slope towards right
    // because of this there are two possibilites
    //1. if the slope keeps increasing to the very end, the last element becomes a peak
    // because we know nums[-1] = nums[n] = inifinity (i.e first and last element are striclty greater than elements outside of the array)
    // 2. the slope eventually steeps down somewhere, the point before the slope steeps down is where we could say that a peak exists
    int n = nums.size();
    int low = 0 , high = n - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        // there is an increasing trend / slope towards right
        if(nums[mid] < nums[mid + 1]){
            low = mid + 1;
        }
        // there is an increasing trend / slope towards left
        // nums[mid] > nums[mid + 1]
        else{
            // because mid could itself be a peak according to the condition 
            high = mid;
        }
    }
    // at the eventually low will be pointing towards a peak
    // since for this problem we aren't supposed to justify a peak's identity
    // but a peak's existence 
    // and by all the operations we are making sure we are eliminating the space
    // where we don't have a peak
    return high;
    }
};