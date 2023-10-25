class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
private:
    void backtrack(int start, int n, int k, vector<int>& current,      vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int num = start; num <= n - (k - current.size()) + 1; num++) {
            current.push_back(num);
            backtrack(num + 1, n, k, current, result);
            current.pop_back();
        }
    }
};