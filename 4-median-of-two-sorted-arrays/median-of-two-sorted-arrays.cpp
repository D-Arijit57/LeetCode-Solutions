class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for optimization
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2; // Elements needed on left side
        
        int left = 0, right = m;
        
        while (left <= right) {
            // Partition nums1 at i, nums2 at j
            int i = (left + right) / 2;
            int j = half - i;
            
            // Get boundary values
            int nums1Left = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1Right = (i == m) ? INT_MAX : nums1[i];
            int nums2Left = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2Right = (j == n) ? INT_MAX : nums2[j];
            
            // Check if partition is correct
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                // Found correct partition
                if (total % 2 == 1) {
                    // Odd total length - return max of left side
                    return max(nums1Left, nums2Left);
                } else {
                    // Even total length - return average of middle two
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                }
            }
            else if (nums1Left > nums2Right) {
                // nums1 partition too far right, move left
                right = i - 1;
            }
            else {
                // nums1 partition too far left, move right
                left = i + 1;
            }
        }
        
        return 0.0; // Should never reach here with valid input
    }
};