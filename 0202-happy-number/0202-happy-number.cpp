class Solution {
public:
    // calculating the sum of square of digits
    int next(int n){
        int sum = 0;
        while(n > 0){
            int r = n % 10;
            sum += r * r;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        while(true){
            slow = next(slow);
            fast = next(next(fast));
            // if slow ever becomes 1 then there's no cycle
            if(slow == 1){
                return true;
            }
            // in case a number repeats , there is a cycle
            if(slow == fast){
                break;
            }
        }
        return false;
    }
};