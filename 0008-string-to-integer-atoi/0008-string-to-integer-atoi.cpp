class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        while(s[i] == ' '){ 
            i++;
        }

        int pos = 0, neg = 0; 

        if(s[i] == '+'){
            pos++; 
            i++;
        }

        if(s[i] == '-'){
            neg++; 
            i++;
        }

        double result = 0; 

        while(i<n and s[i] >= '0' and s[i] <= '9'){
            result = result*10 + (s[i] - '0'); 
            i++;
        }

        if(neg > 0) 
            result = -result;
        if(pos > 0 and neg > 0) 
            return 0;

        if(result > INT_MAX) 
            result = INT_MAX;

        if(result < INT_MIN) 
            result = INT_MIN;

        return (int)result;
    }
        };