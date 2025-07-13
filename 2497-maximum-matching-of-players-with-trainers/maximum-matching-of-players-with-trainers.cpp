class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int cnt = 0;
        int playerIdx = 0, trainerIdx = 0;
        
        while (playerIdx < players.size() && trainerIdx < trainers.size()) {
            if (players[playerIdx] <= trainers[trainerIdx]) {
                // Match found
                cnt++;
                playerIdx++;
                trainerIdx++;
            } else {
                // Current trainer can't train current player
                // Move to next trainer
                trainerIdx++;
            }
        }
        
        return cnt;
    }
};