class Solution {
public:
    bool doExists(vector<int>&row, int target){
        int n = row.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(row[mid] > target) high = mid - 1;
            else if(row[mid] < target) low = mid + 1;
            else return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // take each row, search in it individually using binary search
        int rows = matrix.size();
        int row = 0;
        while(row < rows){
            if(doExists(matrix[row], target)){
                return true;
            }
            else row++;
        }
        return false;
    }
};