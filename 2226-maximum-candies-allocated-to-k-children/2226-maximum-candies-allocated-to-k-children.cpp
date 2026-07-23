class Solution {
public:
    bool canDistribute(vector<int>& candies, int p, long long k) {
        int n = candies.size();
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            // can we atleast have p piles from each candies[i]
            // count the number of complete groups  
            cnt += floor(candies[i] / p);
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        // the search space belongs from the 1 to max element
        // we can atleast distrbute one candy from each of the candies[i] piles
        // as per the constraints
        /*
        1 <= candies.length <= 105
        1 <= candies[i] <= 107
        1 <= k <= 1012
        */
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // if it works we can check if there is a larger value if which can
            // work so we eliminate the left search space
            if (canDistribute(candies, mid, k)) {
                ans = mid;
                low = mid + 1;
            }
            // if it doesn't work then the ammount of candies is large
            // we should check for a smaller value
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};