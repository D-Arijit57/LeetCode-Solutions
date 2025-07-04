class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        return helper(k, ops, 0);
    }
    char helper(long long k, vector<int> ops, int shift) {
        if (ops.empty()) return 'a' + (shift % 26);
        int n = ops.size();
        long long half = (n - 1 >= 60) ? LLONG_MAX : (1LL << (n - 1));
        vector<int> sub(ops.begin(), ops.end() - 1);
        return k <= half ? helper(k, sub, shift) : helper(k - half, sub, shift + ops.back());
    }
};