class Solution {
public:
    int calculate_sumOfdigits(int n){
        int sum = 0;
        while(n > 0){
            int remainder = n % 10;
            sum += remainder * remainder;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n,fast = n;
        while(true){
         slow = calculate_sumOfdigits(slow);
         fast = calculate_sumOfdigits(fast);
         fast = calculate_sumOfdigits(fast);
         n = slow;
         if(fast == 1) return true ;
         if(slow == fast) return false;
        }
        return true;
    }
};