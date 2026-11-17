class Solution {
public:
    bool canShip(vector<int>&weights, int days, int cap){
        int currWeight = 0, currDays = 1;
        for(int i = 0 ; i < weights.size(); i++){
            // if adding the current weight makes the currWeight more than the capacity 
            // we need to ship it the next day 
            if(currWeight + weights[i] > cap){
                currWeight = 0;
                currDays++;

                if(currDays > days) return false;
            }
            // after reseting currWeight (in case it needs) 
            // add the current weight
            currWeight += weights[i];
        }
        // check if the current count of days is lesser than the required days
        return currDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // search space 
        // weights
        // starting from the maximum weight till the summation of all weights
        // monotonicity : increasing
        // TTTTTTFFFFFFF
        int n = weights.size();
        // because the belt should be able to carry atleast the maximum weight in a single day itself
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low < high){
            int mid = low + (high - low) / 2;

            // minimize the weight capacity
            // if the weight can be shipped minimize the capacity
            // look for a smaller capacity
            if(canShip(weights, days, mid)){
                high = mid;
            }
            // if we can't ship the weight
            // we need to increase the capacity
            else low = mid + 1; 
        }
        return high;
    }
};