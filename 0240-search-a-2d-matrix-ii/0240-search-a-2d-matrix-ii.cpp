class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // staircase 
        int rows = matrix.size();
        int cols = matrix[0].size();


        // Start from the top-right corner.
        // This corner is special because:
        // - Every element to the left is smaller.
        // - Every element below is larger.
        int row = 0, col = cols - 1;
        while(row < rows && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }

            // Current element is too large.
            // Since every element below it in the same column is even larger,
            // the target cannot exist in this column.
            // move left 
            else if(matrix[row][col] > target){
                col--; 
            }

            // Current element is too small.
            // Since every element to its left in the same row is even smaller,
            // the target cannot exist in this row.
            // move down 
            else row++; 
        }
        return false;
    }
};