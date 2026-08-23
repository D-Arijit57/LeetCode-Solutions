class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0, prod = 1;
        while(num > 0){
            int r = num % 10;
            sum += r;
            prod *= r;
            num /= 10;
        }
        int divisor = sum + prod;
        if(n % divisor == 0) return true;
        return false;
    }
};