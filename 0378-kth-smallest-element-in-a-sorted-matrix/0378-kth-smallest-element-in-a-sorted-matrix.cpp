class Solution {
public:
    int countLessEqual(vector<int>&row, int x){
        // since each row is sorted, we can use a binary search instead of a linear one
        int low = 0, high = row.size();
        while(low < high){
            int mid = low + (high - low) / 2;
            // if current element is greater than the candidate
            // all the elements after it would be greater than it
            // so remove the right half
            if(row[mid] > x){
                high = mid;
            }
            // if its smaller than candidate, all the elements before it would be smaller as well
            // so we should remove the left half
            else low = mid + 1;
        }
        // at the end low will be the number of elements that is atleast greater than x
        // >= x
        return low;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // a element is called the kth smallest element
        // if it has exactly k - 1 smaller elements before it
        // or atleast k smaller elements before it
        if(matrix.size() <= 1) return matrix[0][0];
        int n = matrix.size();
        // the search space belongs from the first element to the last element
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low < high){
            // mid represents the candidate element index for the kth smallest
            long long mid = low + (high - low) / 2;
            // check in total how many elements are smaller than mid
           
            int totalCnt = 0 ;
            // for each row, check how many elements are smaller than x 
            for(auto row : matrix){
                totalCnt +=  countLessEqual(row, mid);
            }
            // if its lesser than k, then its too small for to have atleast k elememts smaller than it
            if(totalCnt < k){
                low = mid + 1;
            }
            // if its greater than k then the mid should be smaller
            else{
                high = mid;
            }
        }
        return low;
    }

};