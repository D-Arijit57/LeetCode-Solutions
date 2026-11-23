class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket sort : optimized TC O(N)
        // Instead of organizing elements using a heap, we can create an array where the index itself represents the frequency.
        if(nums.empty()) return {};
        int n = nums.size();

        // record the frequency of each element in a hashmap
        unordered_map<int,int>freq;
        for(const int &num : nums){
            freq[num]++;
        }


        // create buckets with the size of n + 1
        // why n + 1 ? 
        // Because frequency can range from 1 to n, and we want to use the frequency directly as the bucket index.
        vector<vector<int>>buckets(n + 1);
        for(const auto &it : freq){
            buckets[it.second].push_back(it.first);
        }

        vector<int>ans;
        // taverse from the back to retrieve the top k frequent
        int i = n;
        while(i >= 1 && ans.size()!= k){
            for(const auto &it : buckets[i]){
                if(ans.size() == k) break;
                ans.push_back(it);
            }
            i--;
        }
        return ans;
    }

};