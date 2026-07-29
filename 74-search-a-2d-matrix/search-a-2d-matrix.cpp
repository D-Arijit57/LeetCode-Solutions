class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // the search space is the entire matrix
        // it starts from first element of the first row till last element of the last row 
        // since the matrix is sorted in non-decreasing order
        // it already has monotonicity
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0, high = rows * cols  - 1;
        while(low <= high){
            // mid represents the index of the candidate element
            // but it doesn't in which row it is it
            int mid = low + (high - low) / 2;
            // to calculate that we have flatten the indices
            // we can do that by dividing the index by the no of cols
            // it simply tanslates how many complete rows have we passed 
            int curr_row = mid / cols;
            // we have to make sure the col is flattened as well or it may generate out of bound errors
            // for example, we have mid = 5 and we are at row = 0
            // indices are 0 1 2 3 , mid = 5 accessing it produces out of bound
            // so we have to divide it by column size to flatten it and map it to the exact distance its far the start of the row
            int curr_col = mid % cols;
            if(matrix[curr_row][mid % cols] > target) high = mid - 1;
            else if(matrix[curr_row][mid % cols] < target) low = mid + 1;
            else return true;
        }
        return false;
    }
};