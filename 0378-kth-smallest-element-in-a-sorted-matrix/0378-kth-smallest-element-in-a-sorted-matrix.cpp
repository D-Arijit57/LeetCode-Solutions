class Solution {
public:
// Tc : n^2 log (minVal - maxVal) or n^2 log (range)
    int countLessEqual(vector<int>&row, int x){
       int low = 0, high = row.size();
       while(low < high){
        int mid = low + (high - low) / 2;
        if(row[mid] > x)high = mid;
        // when its <= x, move the low just after the smallest or equal element 
        else low = mid + 1;
       }
       // at the end low represents the element > x 
       return low;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // A value x is large enough to be the kth smallest
        // if at least k elements are <= x.
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