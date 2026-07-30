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
        // Every row is individually sorted.
        // A row is worth binary searching only if the target lies
        // within the row's value range [first, last].
        for (vector<int>& row : matrix) {
            // a target can only lie inside the row
            // if row.front() <= target <= row.back()
            if (row.front() <= target && target <= row.back()) {
                if (doExists(row, target))
                    return true;
            }
        }
        return false;
    }
};