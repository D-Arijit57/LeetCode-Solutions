class Solution {
public:
    bool isSymmetric(int num){
        string numstr = to_string(num);
        int n = numstr.size();
        if(n % 2 != 0){
            return false;
        }
        int sum1 = 0 , sum2 = 0;

        for(int i = 0; i<n/2 ; i++){
            sum1 += numstr[i] - '0';
            sum2 += numstr[n-1-i] - '0';
        }
        return sum1 == sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int num = low ; num <= high ; num++){
            if(isSymmetric(num) == true){
                cnt++;
            }
        }
        return cnt;
    }

};