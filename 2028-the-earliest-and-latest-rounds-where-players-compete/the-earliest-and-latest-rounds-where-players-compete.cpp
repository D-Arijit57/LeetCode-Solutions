class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // Use memoization to cache results
        map<vector<int>, pair<int, int>> memo;
        
        // Initialize the tournament with players 1 to n
        vector<int> players;
        for (int i = 1; i <= n; i++) {
            players.push_back(i);
        }
        
        auto result = dfs(players, 1, firstPlayer, secondPlayer, memo);
        return {result.first, result.second};
    }
    
private:
    pair<int, int> dfs(vector<int>& players, int round, int first, int second, 
                      map<vector<int>, pair<int, int>>& memo) {
        // Check if result is already computed
        if (memo.count(players)) {
            return memo[players];
        }
        
        int n = players.size();
        
        // Base case: if only 1 or 2 players left
        if (n <= 1) {
            return {INT_MAX, INT_MAX};
        }
        
        // Check if first and second players compete in this round
        bool competeThisRound = false;
        int left = 0, right = n - 1;
        
        while (left < right) {
            if ((players[left] == first && players[right] == second) ||
                (players[left] == second && players[right] == first)) {
                competeThisRound = true;
                break;
            }
            left++;
            right--;
        }
        
        if (competeThisRound) {
            memo[players] = {round, round};
            return {round, round};
        }
        
        // Generate all possible outcomes for this round
        vector<vector<int>> allOutcomes = generateOutcomes(players, first, second);
        
        int earliest = INT_MAX;
        int latest = 0;
        
        for (auto& outcome : allOutcomes) {
            auto [early, late] = dfs(outcome, round + 1, first, second, memo);
            earliest = min(earliest, early);
            latest = max(latest, late);
        }
        
        memo[players] = {earliest, latest};
        return {earliest, latest};
    }
    
    vector<vector<int>> generateOutcomes(vector<int>& players, int first, int second) {
        vector<int> winners;
        vector<vector<int>> results;
        
        generateOutcomesHelper(players, 0, players.size() - 1, first, second, winners, results);
        return results;
    }
    
    void generateOutcomesHelper(vector<int>& players, int left, int right, int first, int second,
                               vector<int>& winners, vector<vector<int>>& results) {
        if (left > right) {
            // All matches processed, add this outcome
            vector<int> outcome = winners;
            sort(outcome.begin(), outcome.end());
            results.push_back(outcome);
            return;
        }
        
        if (left == right) {
            // Middle player advances automatically
            winners.push_back(players[left]);
            generateOutcomesHelper(players, left + 1, right - 1, first, second, winners, results);
            winners.pop_back();
            return;
        }
        
        int p1 = players[left];
        int p2 = players[right];
        
        // Special players always win
        if (p1 == first || p1 == second) {
            winners.push_back(p1);
            generateOutcomesHelper(players, left + 1, right - 1, first, second, winners, results);
            winners.pop_back();
        } else if (p2 == first || p2 == second) {
            winners.push_back(p2);
            generateOutcomesHelper(players, left + 1, right - 1, first, second, winners, results);
            winners.pop_back();
        } else {
            // Either player can win - explore both possibilities
            // Try p1 wins
            winners.push_back(p1);
            generateOutcomesHelper(players, left + 1, right - 1, first, second, winners, results);
            winners.pop_back();
            
            // Try p2 wins
            winners.push_back(p2);
            generateOutcomesHelper(players, left + 1, right - 1, first, second, winners, results);
            winners.pop_back();
        }
    }
};