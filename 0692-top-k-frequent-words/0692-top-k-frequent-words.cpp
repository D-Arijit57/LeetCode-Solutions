class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(words.empty()) return {};
        // using bucket sort
        unordered_map<string, int>freq;
        // record the frequency
        for(const auto &word: words){
            freq[word]++;
        }

        // create the frequency buckets
        vector<vector<string>>buckets(words.size() + 1);
        // frequency wise distribute them
        for(const auto &it : freq){
            buckets[it.second].push_back(it.first);
        }
        
        // since we are getting the lexicographically smaller words from each bucket
        // each bucket should be sorted first
        for(auto &bucket : buckets){
            sort(bucket.begin(), bucket.end());
        }

        vector<string>ans;
        int i = words.size();
        // traverse backwords 
        // to find the top k frequents
        while( i >= 1 && ans.size() < k){
            // for each bucket
            // push all the words inside the bucket
            for(const string &str: buckets[i]){
                if(ans.size() == k) break;
                ans.push_back(str);
            }   
            i--;
        }
        return ans;
    }
};