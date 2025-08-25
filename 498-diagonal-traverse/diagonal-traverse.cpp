class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        
        int row = 0, col = 0;
        bool goingUp = true;
        
        for (int i = 0; i < m * n; i++) {
            result.push_back(mat[row][col]);
            
            if (goingUp) {
                // Moving diagonally up-right
                if (col == n - 1) {
                    // Hit right boundary, move down and change direction
                    row++;
                    goingUp = false;
                } else if (row == 0) {
                    // Hit top boundary, move right and change direction
                    col++;
                    goingUp = false;
                } else {
                    // Normal diagonal movement up-right
                    row--;
                    col++;
                }
            } else {
                // Moving diagonally down-left
                if (row == m - 1) {
                    // Hit bottom boundary, move right and change direction
                    col++;
                    goingUp = true;
                } else if (col == 0) {
                    // Hit left boundary, move down and change direction
                    row++;
                    goingUp = true;
                } else {
                    // Normal diagonal movement down-left
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};