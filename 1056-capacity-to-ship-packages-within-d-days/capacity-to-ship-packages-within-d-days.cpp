class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap){
        int n = weights.size();
        // we atleast need 1 day to ship one package so it starts from 1 
        int currWeight = 0, dayUsed = 1;
        for(int i = 0 ; i < n ; i++){
            // if weights[i] makes current weight reaches the limit of the capactiy
            // start a new day
            if(currWeight + weights[i] > cap){
                currWeight = 0;
                dayUsed++;
            }
            currWeight += weights[i];
        }
        return dayUsed <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // the search space is the capacity
        // for a certain number weights if you want to ship all the weights you need to choose atleast the maximum weight
        // because inidividually it won't be possible for you to ship it without choosing the capacity as same as it
        // at max the capacity can be sum of all the weights
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // if you have found a capacity that works then look for a more valid one in the left
            if(canShip(weights, days,  mid)){
                ans = mid;
                high = mid - 1;
            }
            // the capacity is too low, we need a larger one
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};