class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        
        // Check all pairs of points
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                int x1 = points[i][0], y1 = points[i][1];  // Point A
                int x2 = points[j][0], y2 = points[j][1];  // Point B
                
                // Check if A is upper left of B
                // A.x <= B.x and A.y >= B.y
                if (x1 <= x2 && y1 >= y2) {
                    bool validPair = true;
                    
                    // Check if any other point lies in the rectangle
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        
                        int x3 = points[k][0], y3 = points[k][1];
                        
                        // Check if point k is in the rectangle (including border)
                        // Rectangle has top-left at (x1, y1) and bottom-right at (x2, y2)
                        if (x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
                            validPair = false;
                            break;
                        }
                    }
                    
                    if (validPair) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};

// Alternative solution with cleaner helper function
class Solution2 {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isValidPair(points, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    bool isValidPair(vector<vector<int>>& points, int i, int j) {
        int x1 = points[i][0], y1 = points[i][1];  // Point A
        int x2 = points[j][0], y2 = points[j][1];  // Point B
        
        // Check if A is upper left of B
        if (!(x1 <= x2 && y1 >= y2)) {
            return false;
        }
        
        // Check if any other point lies in the rectangle
        for (int k = 0; k < points.size(); k++) {
            if (k == i || k == j) continue;
            
            int x3 = points[k][0], y3 = points[k][1];
            
            // Point is in rectangle if it's within bounds (inclusive)
            if (x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
                return false;
            }
        }
        
        return true;
    }
};