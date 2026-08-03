class Solution {
public:
    int countLessEqual(vector<int>&row, int x){
        int low = 0, high = row.size();
        while(low < high){
            int mid = low + (high - low) / 2;
            if(row[mid] > x){
                high = mid;
            }
            else low = mid + 1;
        }
        return low;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // a element is called the kth smallest element
        // if it has exactly k - 1 smaller elements before it
        // or atleast k smaller elements before it
        if(matrix.size() <= 1) return matrix[0][0];
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low < high){
            // mid represents the candidate element index for the kth smallest
            long long mid = low + (high - low) / 2;
            // check how many elements are <= mid
            // if its greater than k then the mid should be smaller
            int totalCnt = 0 ;
            for(auto row : matrix){
                totalCnt +=  countLessEqual(row, mid);
            }
            // if cnt is greater then trim down the right search space 
            if(totalCnt < k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }

};