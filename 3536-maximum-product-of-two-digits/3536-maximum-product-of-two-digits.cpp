class Solution {
public:
    int maxProduct(int n) {
        int largest_digit = 0;
        int secondLargest_digit = 0;
        while(n > 0){
            int digit = n % 10;
            if (digit >= largest_digit) {
                secondLargest_digit = largest_digit;
                largest_digit = digit;
            } 
            else if (digit > secondLargest_digit) {
                secondLargest_digit = digit;
            }
            n /= 10;
        }
        return largest_digit * secondLargest_digit;
    }
};