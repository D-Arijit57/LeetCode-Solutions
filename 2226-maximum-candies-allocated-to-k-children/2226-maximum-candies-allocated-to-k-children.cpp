class Solution {
public:
    bool canGive(vector<int>& candies, int mid, long long k){
        int n = candies.size();
        long long cnt = 0;
        for(int i = 0; i < n ; i++){
            // we have to check how many children this pile can satisfy
            // for that count the complete groups of that pile while dividing by the mid
            // e.g candies = [10], mid = 3, 10/3 = 3 -> 3+3+3 = almost 10, so we are checking how many children can have exactly 3 candies
            cnt += candies[i] / mid;
            
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        // we can assign 1 candy to a child at minimum
        // at max we can assign the max pile among the candies to a child
        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // if the candidate works we look for a larger one
            // since we are trying to maximize the answer
            if(canGive(candies, mid, k)){
                ans = mid;
                low = mid + 1;
            } 
            // otherwise we look for smaller one
            else high = mid - 1;
        }
        return ans;
    }
};