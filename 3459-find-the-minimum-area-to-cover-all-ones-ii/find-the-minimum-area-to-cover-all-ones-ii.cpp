class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = INT_MAX;
        
        // Try all 6 possible arrangements
        
        // 1. Three horizontal strips: top | middle | bottom
        for (int i1 = 1; i1 < m; i1++) {
            for (int i2 = i1 + 1; i2 < m; i2++) {
                int area1 = getRectArea(grid, 0, i1 - 1, 0, n - 1);
                int area2 = getRectArea(grid, i1, i2 - 1, 0, n - 1);
                int area3 = getRectArea(grid, i2, m - 1, 0, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // 2. Three vertical strips: left | middle | right
        for (int j1 = 1; j1 < n; j1++) {
            for (int j2 = j1 + 1; j2 < n; j2++) {
                int area1 = getRectArea(grid, 0, m - 1, 0, j1 - 1);
                int area2 = getRectArea(grid, 0, m - 1, j1, j2 - 1);
                int area3 = getRectArea(grid, 0, m - 1, j2, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // 3. Top-left + Top-right + Bottom
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int area1 = getRectArea(grid, 0, i - 1, 0, j - 1);
                int area2 = getRectArea(grid, 0, i - 1, j, n - 1);
                int area3 = getRectArea(grid, i, m - 1, 0, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // 4. Top + Bottom-left + Bottom-right
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int area1 = getRectArea(grid, 0, i - 1, 0, n - 1);
                int area2 = getRectArea(grid, i, m - 1, 0, j - 1);
                int area3 = getRectArea(grid, i, m - 1, j, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // 5. Left + Top-right + Bottom-right
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int area1 = getRectArea(grid, 0, m - 1, 0, j - 1);
                int area2 = getRectArea(grid, 0, i - 1, j, n - 1);
                int area3 = getRectArea(grid, i, m - 1, j, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // 6. Top-left + Bottom-left + Right
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int area1 = getRectArea(grid, 0, i - 1, 0, j - 1);
                int area2 = getRectArea(grid, i, m - 1, 0, j - 1);
                int area3 = getRectArea(grid, 0, m - 1, j, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        return result;
    }
    
private:
    // Calculate the minimum rectangle area to cover all 1's in the given region
    int getRectArea(vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        int minRow = r2 + 1, maxRow = r1 - 1;
        int minCol = c2 + 1, maxCol = c1 - 1;
        
        // Find the bounding box of all 1's in this region
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        
        // If no 1's found, return 0 (invalid case)
        if (minRow > maxRow || minCol > maxCol) {
            return 0;
        }
        
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};