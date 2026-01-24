class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.size() , n2 = t.size();
        int i = n1 - 1 , j = n2 - 1;
        // cnt's for the #'s
        int skipS = 0,skipT = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    skipS++;
                    i--;
                }
                else if(skipS > 0){
                    skipS--;
                    i--;
                }
                else break;
            }
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
            if(i >= 0 && j >= 0){
                if(s[i] != t[j]) return false;
            }
            // incase one pointer finishes first means both string are not of same length 
            if((i >= 0)  !=  (j >= 0)) return false;
            i--;
            j--;
        } 
        return true;
    }
};