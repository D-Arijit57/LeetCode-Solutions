class Solution {
public:
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
        if(n == 1) return true;
        int slow = n , fast = n;
        while(true){
            slow = next(slow);
            fast = next(next(fast));
            if(fast == 1) break;
            if(slow == fast) return false;
        }
        return true;
    }
};