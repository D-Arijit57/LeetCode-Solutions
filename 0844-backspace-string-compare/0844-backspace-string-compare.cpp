class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // we're gonna start iterating from the back
        // and continously compare the strings (performing the skip operations if # appear)
        // to check if they stay the same
        // if at any point we find the difference
        // or one string runs out before the other one then we return false
        int n = s.size(), m = t.size();
        int skipS = 0, skipT = 0;
        int right1 = n - 1, right2 = m - 1;
        while(right1 >= 0 || right2 >= 0){
              // skip operations for s
            while(right1 >= 0){
                if(s[right1] == '#'){
                    skipS++;
                    right1--;
                } 
                else if(skipS > 0){
                    skipS--;
                    right1--;
                }
                else break;
            }
            // skip operations for t
            while(right2 >= 0){
                if(t[right2] == '#') {
                    skipT++;
                    right2--;
                }
                else if(skipT > 0){
                    skipT--;
                    right2--;
                }
                else break;
            }
            // compare both of the string 
            // if both them exists check if they are pointing towards the same character
            if(right1 >= 0 && right2 >= 0){
                if(s[right1] != t[right2]) return false;
            }
            // check if only one them exists
            // then they are not the same
            else if(right1 >= 0 || right2 >= 0) return false;

            // if both pointer exists 
            // and they are pointing towards the same character
            // move them both towards the left
            right1--;
            right2--;
            
        }

        return true;
    }
};