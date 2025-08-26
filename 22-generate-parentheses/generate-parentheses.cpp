class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans ;
        string curr = "";
        backtrack(ans,curr,0,0,n);
        return ans;
    }
private:
    void backtrack(vector<string>&ans, string curr, int open , int close, int n){
        // base case : if we've built a string with the length of 2 * n
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }

        // adding open parentheses till we can ( if we haven't used up all the open parentheses )
        if(open < n){
            curr += '(';
            backtrack(ans,curr,open + 1,close,n);
            curr.pop_back();
        }
        //adding the close parentheses till we can( if the number of open parentheses if atleast one greater than the closed ones)
        if(close < open){
            curr += ')';
            backtrack(ans,curr,open,close + 1, n);
            curr.pop_back();
        }
    }   
};