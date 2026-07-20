class Solution {
public:
    bool canMakeDay(vector<int>&bloomDay,int k, int dayCount, int m){
        // position matters as well because for example : 
        // bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
        //Here is the garden after the 7 and 12 days:
        // After day 7: [x, x, x, x, _, x, x]
        // We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
        // After day 12: [x, x, x, x, x, x, x]
        // It is obvious that we can make two bouquets in different ways.
        int n = bloomDay.size();
        int consecutive = 0 , bouquets = 0;
        for(int i = 0 ; i < n ; i++){
            // we can use the flowers which are bloomed till ith day
            // we need to make sure they are as adjacent as k
            // k = 3, those three flowers should be adjacent 
            if(dayCount >= bloomDay[i]) {
                consecutive++;
                // if we have enough consecutive flowers to make the bouquet
                // count bouquet
                if(consecutive == k) {
                    bouquets++;
                    consecutive = 0;
                }
            }
            // since the adjacency break we need to reset it to zero 
            else consecutive = 0;
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) { 
    // edge case : if the total number of flowers is greater than the number of flowers it has then for sure we can't make bouquets
    if(bloomDay.size() < (long long)m * k) return -1;
    // the search space here is the days the flowers bloom :  min day to max day
    // total number of flower required per bouquet is k
    int n = bloomDay.size();
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int countBouquets = 0, ans = -1;
    // we have to minimize the number of days required
    while(low <= high){
        int mid = low + (high - low) / 2;
        // check if have the required flowers to make the bouquet
        // we can make bouquets,only if the count is a multiple of k
        if(canMakeDay(bloomDay,k,mid,m)){
            // since we have already available flowers
            // there's a possibility of bloomed flowers on the right side
            ans = mid;
            high = mid - 1;   
        } 
        // if we don't have available flowers move right 
        else low = mid + 1;
        }
    return ans;
    }
};