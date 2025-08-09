class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for each individual row and col maintain hashsets
        unordered_set<char>rows[9];
        unordered_set<char>cols[9];

        // for each indidvidual 3x3 boxes maintain a map 
        // where the key => pair <int, int> (for co-ordinates) 
        // and the value is a hashset to check if the value repeats 
        map<pair<int, int>, unordered_set<char>>boxes;
        
        // iterate through the entire sudoku board 
        for(int row = 0 ; row < 9 ; row++){
            for(int col = 0 ; col < 9 ; col++){
                char val = board[row][col];

                // skip the empty cells 
                if(val == '.') continue;

                // for each row  and col check if the value repeats 
                // if value doesn't repeat insert the value 
                if(rows[row].count(val)) return false;
                
                rows[row].insert(val);

                if(cols[col].count(val)) return false;

                cols[col].insert(val);
                
                // now check for each of the 3x3 boxes 
                // pair <int , int> key will be {row/3,col/3} to check for the co-ordindates
                // if value doesn't repeat insert that value in that specific cell 
                pair<int,int>keyBox = {row/3 ,col/3};
                if(boxes[keyBox].count(val)) return false;
                boxes[keyBox].insert(val);
            }

        }
        return true;
    }
};