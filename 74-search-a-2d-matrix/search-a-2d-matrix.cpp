class Solution {
    // Recursive Version
public:
    bool bs(vector<vector<int>>&matrix , int low, int high , int target, int m){
        if(low > high) return false;
        int mid = low + (high - low) / 2;
        int row = mid / m , col = mid % m;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) return bs(matrix , low , mid - 1 ,target,m);
        else return bs(matrix, mid+1, high, target,m);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();
        return bs(matrix,0,(n*m - 1),target,m);
    }
};
