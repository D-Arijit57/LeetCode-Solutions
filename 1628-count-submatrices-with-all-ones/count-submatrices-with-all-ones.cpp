
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> heights(n, 0);
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            // Update heights for current row
            for (int j = 0; j < n; j++) {
                heights[j] = mat[i][j] == 0 ? 0 : heights[j] + 1;
            }
            
            // Count submatrices ending at row i using histogram approach
            result += countSubmatricesInHistogram(heights);
        }
        
        return result;
    }
    
private:
    int countSubmatricesInHistogram(vector<int>& heights) {
        int n = heights.size();
        int count = 0;
        
        // For each position, count rectangles with that position as rightmost column
        for (int i = 0; i < n; i++) {
            int minHeight = heights[i];
            
            // Extend leftward and count rectangles
            for (int j = i; j >= 0; j--) {
                minHeight = min(minHeight, heights[j]);
                if (minHeight == 0) break;
                
                // Add rectangles of all possible heights from 1 to minHeight
                // with width from j to i (inclusive)
                count += minHeight;
            }
        }
        
        return count;
    }
};