class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // valid window would where window.size() <= 2
        // since we have two baskets and each basket can only hold a single type of fruit
        int n = fruits.size();
        unordered_map<int,int>freq;
        // the left boundary of the window
        int left = 0;
        int ans = INT_MIN;
        for(int right = 0; right < n ; right++){
            freq[fruits[right]]++;

            // shrink: invalid window : window.size() > 2
            while(freq.size() > 2){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
                // if the frequency becomes zero : that is the type of fruit doesn't exist in the window
                // then make sure you remove it from the window
               
            }
            // for each valid window, we're going to update the maximum length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};