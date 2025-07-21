class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if numRows is 1 or string length <= numRows
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }
        
        // Create vectors to store characters for each row
        vector<string> rows(numRows);
        
        int currentRow = 0;
        bool goingDown = false;
        
        // Iterate through each character in the string
        for (char c : s) {
            // Add character to current row
            rows[currentRow] += c;
            
            // Change direction when we reach top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to next row based on direction
            currentRow += goingDown ? 1 : -1;
        }
        
        // Concatenate all rows to form the result
        string result = "";
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};