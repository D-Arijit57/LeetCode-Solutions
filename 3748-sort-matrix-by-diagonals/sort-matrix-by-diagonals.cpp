class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Process bottom-left triangle (including main diagonal)
        // These diagonals should be sorted in non-increasing order
        for (int d = 0; d < n; d++) {
            // Diagonal starting at (d, 0)
            vector<int> diagonal;
            vector<pair<int, int>> positions;
            
            // Collect elements from this diagonal
            for (int i = d, j = 0; i < n && j < n; i++, j++) {
                diagonal.push_back(grid[i][j]);
                positions.push_back({i, j});
            }
            
            // Sort in non-increasing order
            sort(diagonal.begin(), diagonal.end(), greater<int>());
            
            // Put back sorted elements
            for (int k = 0; k < diagonal.size(); k++) {
                grid[positions[k].first][positions[k].second] = diagonal[k];
            }
        }
        
        // Process top-right triangle
        // These diagonals should be sorted in non-decreasing order
        for (int d = 1; d < n; d++) {
            // Diagonal starting at (0, d)
            vector<int> diagonal;
            vector<pair<int, int>> positions;
            
            // Collect elements from this diagonal
            for (int i = 0, j = d; i < n && j < n; i++, j++) {
                diagonal.push_back(grid[i][j]);
                positions.push_back({i, j});
            }
            
            // Sort in non-decreasing order
            sort(diagonal.begin(), diagonal.end());
            
            // Put back sorted elements
            for (int k = 0; k < diagonal.size(); k++) {
                grid[positions[k].first][positions[k].second] = diagonal[k];
            }
        }
        
        return grid;
    }
};