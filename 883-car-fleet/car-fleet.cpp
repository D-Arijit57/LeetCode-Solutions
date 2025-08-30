class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0) return 0;
        // create a pair 
        // to combine the positions along with speed 
        vector<pair<int,int>>cars(n);
        // create variable slowestTime to track the previous car's arrival time 
        int fleets = 0 ; double slowestTime = 0.0;
        for(int i = 0 ; i < n ; i++){
            cars[i] = {position[i],speed[i]};
        }
        // sort the pairs 
        // it'll make sure the cars which are far from the target is at position car[0] and the closes are at car[n-1]
        sort(cars.begin() , cars.end());
        for(int i = n - 1; i >= 0 ; i--){
            double TimeToArrive = static_cast<double>(target - cars[i].first) / cars[i].second;

            // fi this car's arrival time is greatere than the current lead fleet's time.
            // it means this car is slower and cannot catch up 
            // therefore it forms a new fleet
            if(TimeToArrive > slowestTime){
                fleets++;
                // this new , slower fleet becomes the one to catch up to
                slowestTime = TimeToArrive;
            }
            // Why there is no need for counting the merging fleets -- 
            // If timeToArrive  <= slowestTime , this car is fast enough to catch 
            // the lfeet ahead , so it gets absorebed and doesn't form a new fleet 
        }
        return fleets;
    }
};
