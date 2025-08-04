class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i = 0 ; i < n ; i++) {
            freq[nums[i]]++;
        }
        vector<vector<int>> bucket(n + 1);
        
        for(auto& pair : freq) {
            int elem = pair.first;
            int freq = pair.second;
            bucket[freq].push_back(elem);
        }
        vector<int> ans;
        for(int i = n; i >= 0 && ans.size() < k; i--) {
            for(int elem : bucket[i]) {
                ans.push_back(elem);
                if(ans.size() == k) {
                    break;
                }
            }
        }
        
        return ans;
    }
};