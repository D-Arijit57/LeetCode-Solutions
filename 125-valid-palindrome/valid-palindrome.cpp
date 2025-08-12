class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0 , right = n - 1;
        while(left <= right ){
            while (left < right && !isAlphaNumeric(s[left])) left++;
            while (left < right && !isAlphaNumeric(s[right])) right--;
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
 private: bool isAlphaNumeric(char c){
        return isalnum(c);
    }
};