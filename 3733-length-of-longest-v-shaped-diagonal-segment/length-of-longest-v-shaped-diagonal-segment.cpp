class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Define 4 diagonal directions: top-left to bottom-right, bottom-right to top-left,
        // top-right to bottom-left, bottom-left to top-right
        vector<pair<int, int>> directions = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        
        // For each direction, define its clockwise 90-degree turn
        // 0: (1,1) -> (1,-1)
        // 1: (-1,-1) -> (-1,1)  
        // 2: (1,-1) -> (-1,-1)
        // 3: (-1,1) -> (1,1)
        vector<int> clockwiseTurn = {2, 3, 1, 0};
        
        int maxLength = 0;
        
        // Try starting from each cell that contains '1'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // Try each of the 4 diagonal directions
                    for (int dir = 0; dir < 4; dir++) {
                        // Try path without turn
                        int length = getSegmentLength(grid, i, j, dir, -1, -1, directions);
                        maxLength = max(maxLength, length);
                        
                        // Try path with one turn at each possible position
                        length = getSegmentLengthWithTurn(grid, i, j, dir, directions, clockwiseTurn);
                        maxLength = max(maxLength, length);
                    }
                }
            }
        }
        
        return maxLength;
    }
    
private:
    int getSegmentLength(vector<vector<int>>& grid, int startR, int startC, int dir, 
                        int turnR, int turnC, vector<pair<int, int>>& directions) {
        int n = grid.size();
        int m = grid[0].size();
        int r = startR, c = startC;
        int length = 0;
        int expectedValue = 1; // Start with 1
        
        while (r >= 0 && r < n && c >= 0 && c < m) {
            if (grid[r][c] != expectedValue) {
                break;
            }
            
            length++;
            
            // If we've reached the turn position, switch direction
            if (r == turnR && c == turnC && turnR != -1) {
                // This will be handled by the caller
                break;
            }
            
            // Move to next position
            r += directions[dir].first;
            c += directions[dir].second;
            
            // Update expected value for next position
            if (expectedValue == 1) {
                expectedValue = 2;
            } else if (expectedValue == 2) {
                expectedValue = 0;
            } else { // expectedValue == 0
                expectedValue = 2;
            }
        }
        
        return length;
    }
    
    int getSegmentLengthWithTurn(vector<vector<int>>& grid, int startR, int startC, 
                                int initialDir, vector<pair<int, int>>& directions, 
                                vector<int>& clockwiseTurn) {
        int n = grid.size();
        int m = grid[0].size();
        int maxLength = 0;
        
        // Try turning at each position along the initial direction
        int r = startR, c = startC;
        int expectedValue = 1;
        int lengthBeforeTurn = 0;
        
        while (r >= 0 && r < n && c >= 0 && c < m) {
            if (grid[r][c] != expectedValue) {
                break;
            }
            
            lengthBeforeTurn++;
            
            // Try making a turn at this position
            if (lengthBeforeTurn > 1) { // Don't turn at the starting position
                int newDir = clockwiseTurn[initialDir];
                int nextR = r + directions[newDir].first;
                int nextC = c + directions[newDir].second;
                
                // Continue in the new direction
                int lengthAfterTurn = 0;
                int nextExpectedValue = (expectedValue == 1) ? 2 : (expectedValue == 2) ? 0 : 2;
                
                while (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m) {
                    if (grid[nextR][nextC] != nextExpectedValue) {
                        break;
                    }
                    
                    lengthAfterTurn++;
                    nextR += directions[newDir].first;
                    nextC += directions[newDir].second;
                    
                    // Update expected value
                    if (nextExpectedValue == 2) {
                        nextExpectedValue = 0;
                    } else { // nextExpectedValue == 0
                        nextExpectedValue = 2;
                    }
                }
                
                maxLength = max(maxLength, lengthBeforeTurn + lengthAfterTurn);
            }
            
            // Move to next position in initial direction
            r += directions[initialDir].first;
            c += directions[initialDir].second;
            
            // Update expected value
            if (expectedValue == 1) {
                expectedValue = 2;
            } else if (expectedValue == 2) {
                expectedValue = 0;
            } else { // expectedValue == 0
                expectedValue = 2;
            }
        }
        
        // Also consider path without any turn
        maxLength = max(maxLength, lengthBeforeTurn);
        
        return maxLength;
    }
};