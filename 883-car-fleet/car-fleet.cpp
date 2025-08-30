class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0) return 0;
        int fleets = 0; double slowestTime = 0;
        vector<pair<int, int>>cars(n);
        for(int i = 0 ; i < n ; i++){
            cars[i] = {position[i] , speed[i]};
        }
        sort(cars.begin() , cars.end());
        for(int i = n - 1 ; i >= 0 ; i--){
            double timeToArrive = static_cast<double>(target - cars[i].first) / cars[i].second;
            if(timeToArrive > slowestTime){
                fleets++;
                slowestTime = timeToArrive;
            }
        }
        return fleets;
    }
};