class Solution {
public: // - REVISION - 1 - 
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        // MISTAKE 1 : used a vector instead of a map but didn't use a variable for distinct counts
        unordered_map<int,int>freq;
        // MISTAKE 2. set maxLen = INT_MIN -> subarray length is never negative 
        int left = 0, maxLen = 0; 
        for(int right = 0 ; right < n ; right++){
            freq[fruits[right]]++;
            // MISTAKE 1.1 :  Continuation to mistake 1
            // since we used a vector 
            // we couldn't use .erase and because of that 
            // the frequency might have become zero when we shrank the window
            // but the element still stayed in the hash array
            // which resulted of a size staying > 2 always 
            // contributing to a runtime error

            //MISTAKE 1.2 : Forgot to use a distinct count variable for the distinct elements
            // instead of freq.size () > 2 it should've been distinct count > 2
            // although its a bit complex logic compared to map 
            while(freq.size() > 2){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(maxLen,right - left + 1);
        }
        return maxLen;
    }
};