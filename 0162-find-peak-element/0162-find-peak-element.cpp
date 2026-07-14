class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // for this problem we aren't supposed to justify a peak's identity
        // but a peak's existence
        
        // the elimination of either of the halves depends on the mid
        // if nums[mid] < nums[mid + 1] we can see there is an increasing slope
        // towards right because of this there are two possibilites
        // 1. if the slope keeps increasing to the very end, the last element
        // becomes a peak
        // because we know nums[-1] = nums[n] = inifinity (i.e first and last
        // element are striclty greater than elements outside of the array)
        // 2. the slope eventually steeps down somewhere, the point before the
        // slope steeps down is where we could say that a peak exists
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            // there is an increasing trend / slope towards right
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }
            // there is an decreasing trend / slope towards right
            // nums[mid] > nums[mid + 1]
            else {
                // because mid could itself be a peak according to the condition
                high = mid;
            }
        }
        // Eventually the search space shrinks to a single index (low == high).
        // Since every elimination preserves the guarantee that at least one
        // peak exists in the remaining search space, that remaining index must
        // be a peak.
        return low;
    }
};