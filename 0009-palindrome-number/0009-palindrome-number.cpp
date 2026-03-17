class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right){
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
};