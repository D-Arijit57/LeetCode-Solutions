class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        // using bucket sort
        // creating a bucket
        // indices -> frequency of elements (at max the size can be n)
        vector<vector<int>> bucket(n + 1);
        // taking n+1 since the index starts from zero and we wanna take the
        // same size as the array
        for (auto const& pair : freq) {
            int elem = pair.first;
            int cnt = pair.second;
            bucket[cnt].push_back(
                elem); // storing the element corresponding to the count
        }

        // creating the answer array
        vector<int> ans;

        // reiterate the bucket from the back
        for (int i = n; i >= 0 && ans.size() < k; i--) {
            for (int it : bucket[i]) {
                ans.push_back(it);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
    };