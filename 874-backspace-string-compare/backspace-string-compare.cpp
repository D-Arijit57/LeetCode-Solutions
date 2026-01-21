class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int i = n1 - 1 , j = n2 - 1;
        int skipS = 0 , skipT = 0;
        while( i >= 0 || j >= 0){
            // for each character in string 's'
            while(i >= 0){
                // count the number of '#'s if there's any
                if(s[i] == '#'){
                    skipS++;
                    i--;
                }
                // skip the #'s 
                else if(skipS > 0){
                    i--;
                    skipS--;
                }
                else break;
            }
            // do the same for string 't'
            while(j >= 0){
                if(t[j] == '#'){
                    skipT++;
                    j--;
                }
                else if(skipT > 0){
                    skipT--;
                    j--;
                }
                else break;
            }
            // after every skip , check if the two pointers are pointing the same character 
            if(i >= 0 && j >= 0){
                if(s[i] != t[j]) return false;
            }
            // in case one pointer finishes iteration before the other one 
            else if(i >= 0 || j >= 0) return false;
            i--;
            j--;
        }
        return true;
    }
};