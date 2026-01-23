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
        // fast moves +2 ahead and checks if its 1 or same as fast 
        // if its not a happy number it's bound to repeat 
        // it creates a cyclic structure 
        // so we visualize it as a linkedlist to find out using slow and fast pointers
        // if there's a cycle (not a happy number) slow and fast are bound to meet each other
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