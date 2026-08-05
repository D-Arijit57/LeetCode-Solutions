class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we try to make the patitions such that nums1 has equal number of elements to right (or one more in case of odd length)
        // so here we are looking for the partition not the median itself
        // finding the parition to split the arrays will give us the median in O(1)
        // since we make the partitions from the sorted array only, we don't need to check every element out there, we'll checking only the boundary elements of the partition
        // the parition is valid if and only if left1 <= right2 AND left2 <= right1
        // so whenever left1 > right2 we can for sure say that we have too many elements for nums1 (left parition) and move the partition towards left since the array is sorted so moving right only will give us a larger element compared to right2 
        // same with if left2 > rigiht1 then we have take too few elements from nums1 so we should move the parititon towards right
        int n = nums1.size();
        int m = nums2.size();
        // we always create the partitions based on the smaller array
        if(n > m) return findMedianSortedArrays(nums2,nums1);
        // we are not searching indices, we are searching for possible cuts (partitions)
        // the maximum possible cuts we can make is the total length of nums1
        int low = 0, high = n;
        int median = 0;
        while(low <= high){
            // mid represents the partition1 candidate
            // find the left partition, or partition1 
            // it should always have exactly (m+n+1) / 2 elements
            int partition1 = low + (high - low) / 2;
            // the sentinel values (INT_MAX, INT_MIN) helps to maintain the following condition
            // Every partition always has four boundary values (left1, right1, left2, right2), even if one side of a partition is empty.
            int left1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
            int right1 = partition1 == n ? INT_MAX : nums1[partition1];
            // find the right partition to assign left2,right2
            // i.e leftTotal - partition1
            int leftTotal = (n + m + 1) / 2;
            int partition2 = leftTotal - partition1;
            int left2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
            int right2 = partition2 == m ? INT_MAX : nums2[partition2];
            // if the parition1 contains too many elements 
            if(left1 > right2){    
                high = partition1 - 1;
            }
            // if the parition1 contains too few elements
            else if(left2 > right1){
                low = partition1 + 1;
            }
            // the median depends upon the length
            // if its odd then the max of left is the median (the array that contributed to the larger boundary)
            // if its even then its (max(lefts) + min(rights)) / 2.0
            else{
                if( (n + m) % 2 == 0 ) return (max(left1,left2) + min(right1,right2)) / 2.0;
                else return max(left1, left2);
            }
        }
        return -1; 
    }
};