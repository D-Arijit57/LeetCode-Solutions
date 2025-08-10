class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> nCount = getDigitCount(n);
        
        // Check all powers of 2 up to 10^9
        for (int i = 0; i < 30; i++) {  // 2^29 = 536,870,912 < 10^9 < 2^30
            int powerOf2 = 1 << i;  // 2^i
            vector<int> powerCount = getDigitCount(powerOf2);
            
            if (nCount == powerCount) {
                return true;
            }
        }
        
        return false;
    }
    
    private:
    // Helper function to get digit frequency count
    vector<int> getDigitCount(int num) {
        vector<int> count(10, 0);
        while (num > 0) {
            count[num % 10]++;
            num /= 10;
        }
        return count;
    }
};