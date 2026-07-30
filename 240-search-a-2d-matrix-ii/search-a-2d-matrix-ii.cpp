class Solution {
public:
    bool doExists(vector<int>& row, int target) {
        int n = row.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] > target)
                high = mid - 1;
            else if (row[mid] < target)
                low = mid + 1;
            else
                return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Search each row individually using binary search.
        // A row is worth searching only if the target lies within
        // the row's minimum and maximum values.
        int rows = matrix.size();
        int row = 0;
        for (vector<int>& row : matrix) {
            if (row.front() <= target && target <= row.back()) {
                if (doExists(row, target))
                    return true;
            }
        }
        return false;
    }
};