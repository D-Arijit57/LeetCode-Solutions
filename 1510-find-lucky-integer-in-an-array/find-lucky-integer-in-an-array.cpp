class Solution {
public:
    int findLucky(vector<int>& arr) {
         // Count frequency of each number
            unordered_map<int, int> freq;
            for (int num : arr) {
                freq[num]++;
            }
            
            // Find the largest lucky integer
            int maxLucky = -1;
            for (auto& [num, count] : freq) {
                if (num == count) {
                    maxLucky = max(maxLucky, num);
                }
            }
            
            return maxLucky;
    }
};