class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // the problem explicity asks us to solve it in O(log (m + n ))
        // means dividing the search space in half in each iteration 
        // the array are also sorted 
        // we can go for a binary search approach here 
        
        // the search space here is the number of patitions
        // it starts from 1 and goes till the size of the smaller array
        // so if nums1 > nums2 then we have to swap them
        // because nums2 cannot contain all the paritions according to nums1
        // as it's much smaller
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size(), m = nums2.size();

        int low = 0, high = n;

        // mid represents the partition position
        while(low <= high){
            
            // find the partititon for the smaller array
            int partition1 = low + (high - low) / 2;

            // if the partition 0 or n then accessing nums1[0-1] and nums[n] is not a valid index
            // so we assign sentinel values (i.e + and - infinity)
            // this is because no matter what we always want to make sure that we have exactly four boundaries 
            int left1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
            int right1 = partition1 == n ? INT_MAX : nums1[partition1]; 
            
            // if the total length pf the merged array is n + m
            // then for sure one of the half contains exactly n + m / 2 elements
            // now we know it's not confirmed that the length will be always even
            // so to tackle the odd length case we do n + m + 1 / 2
            int leftTotal = (n + m + 1) / 2;

            // why leftTotal - partition1 ?
            // because the partition1 and 2 defines the entire lefthalf of the conceptually merged array not the entire one
            int partition2 = leftTotal - partition1;

            int left2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
            int right2 = partition2 == m ? INT_MAX : nums2[partition2];
            
            // now check the condition 
            // if all the elements in the left are smaller than
            // all the elements in the right 
            // the condition we are checking for is 
            // left1 <= right2 AND right1 <= left2

            // if the left partition contains too many elements
            // shrink the parition position
            if(left1 > right2){
                high = partition1 - 1;
            }

            // if the left partition contains too few elements
            // expand the parition position
            else if(left2 > right1){
                low = partition1 + 1;
            }

            // if the parition position is balanced
            // means all the elements ion the left are smaller all the elements in the right
            else{
                // if its even
                if((n + m) % 2 == 0) return (max(left1,left2) + min(right1,right2)) / 2.0;
                else return max(left1, left2);
            }
        }
        return -1;
    }
};