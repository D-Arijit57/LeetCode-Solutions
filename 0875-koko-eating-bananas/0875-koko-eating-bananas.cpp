class Solution {
public:
    bool canFinish(vector<int>&piles,int k,int h){
        int curr_hours = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            // we need to ceil value because each remaining banana takes an extra hour to consume 
            curr_hours += (piles[i] + k - 1) / k;
        }
        return curr_hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // this is a binary search on answer space problem
        // we need to find a k with which koko can finish eating the bananas before h hours
        int low = 1, high = *max_element(piles.begin(),piles.end());
        while(low < high){
            int mid = low + (high - low) / 2;
            // if it returns true, then all the space after this has a valid k
            // but we want the minimum so we eliminate the right search space
            if(canFinish(piles,mid,h)){
                high = mid;
            }
            // if it returns false, then all the search space before it doesn't contain the answer
            // so eliminate the search space before it
            else low = mid + 1;
        }
        return high;
    }
};