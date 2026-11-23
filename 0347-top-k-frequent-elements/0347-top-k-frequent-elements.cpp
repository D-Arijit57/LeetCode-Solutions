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
        // we need an index equal to n, because the maximum frequency can be n.
        // proof : if we simply use n the indices (here, freq) goes 0,1,2,3,4,5
        // but with n + 1 we have 0,1,2,3,4,5,6 (0 is unused)
        // but we get the highest freq as our index which is 6
        vector<vector<int>>buckets(n + 1);
        for(const auto &it : freq){
            buckets[it.second].push_back(it.first);
        }

        vector<int>ans;
        // taverse from the back to retrieve the top k frequent
        int i = n;
        while(i >= 1 && ans.size()!= k){
            // for each frequency bucket push all the elements in the answer
            for(const auto &it : buckets[i]){
                if(ans.size() == k) break;
                ans.push_back(it);
            }
            i--;
        }
        return ans;
    }

};