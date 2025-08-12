class Solution {
public:
    bool isPalindrome(string s) {
        // two pointer approach 
        int n = s.size();
        // assigning two pointers left and right 
        // one at the beginning of the string and the other one at the end
        int left = 0 , right = n - 1;
        while(left <= right ){
            // we have to skip the non alphanumeric characters from left as well as right
            while (left < right && !isAlphaNumeric(s[left])) left++;
            while (left < right && !isAlphaNumeric(s[right])) right--;
            // for the characters of string since some of them can be uppercase 
            // convert to lowercase before comparing those two 
            // if they are not equal return false
            if(tolower(s[left]) != tolower(s[right])) return false;

            // at the end we are left with only one condition 
            // that is if they are equal 
            // in that case increment left and decrement right 
            left++;
            right--;
        }
        return true;
    }
    //Helper function to check if the character is alphanumeric or not 
 private: bool isAlphaNumeric(char c){
        return isalnum(c);
    }
};