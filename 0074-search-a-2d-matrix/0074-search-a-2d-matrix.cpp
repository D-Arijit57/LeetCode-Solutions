class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Instead of binary searching each row, treat the entire matrix as a
        // virtually flattened sorted array of size (rows * cols).
        int low = 0;
        int high = rows * cols - 1;

        while (low <= high) {

            // 'mid' represents the candidate's index in the virtual 1D array.
            int mid = low + (high - low) / 2;

            // Convert the global (flattened) index back into matrix coordinates.
            // Division tells us how many complete rows have been crossed,
            // which gives the row containing the element.
            int curr_row = mid / cols;

            // Modulo converts the global index into a local column index.
            // It measures the offset from the beginning of the current row,
            // effectively resetting each row's indexing to start from 0.
            int curr_col = mid % cols;
            if (matrix[curr_row][curr_col] > target) high = mid - 1;
            else if (matrix[curr_row][curr_col] < target) low = mid + 1;
            else
                return true;
        }

        return false;
    }
};