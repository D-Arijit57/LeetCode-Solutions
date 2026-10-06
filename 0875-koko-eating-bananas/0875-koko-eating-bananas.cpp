class Solution {
public:
    // feasibility function :
    // if koko can finish eating the bananas within the specified hours
    bool canEat(vector<int>&piles, int k, int h){
        int n = piles.size();
        long long cnt_hours = 0;
        for(int i = 0 ; i < n ; i++){
            cnt_hours += (piles[i] + k - 1) / k;
        }
        return cnt_hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // search space is the number of bananas koko can eat
        int n = piles.size();
        // minimum koko can eat 1 pile / hour 
        // maximum koko can eat n pile / hour, where n is the maximum piles[i] in piles
        int low = 1 , high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(low <= high){
            // mid represents the value of k (or the candidate k we are checking with)
            int mid = low + (high - low) / 2;

            // if it satisfies the condition look for smaller answer
            if(canEat(piles, mid, h)){
                ans = mid;
                high = mid - 1;
            }
            // if it doesn't work then we have to look for a larger answer
            else low = mid + 1;
        }
        return ans;
    }
};