class Solution {
public:
    typedef pair<int, int>freqPair;
    vector<int> topKFrequent(vector<int>& nums, int k) {
          // maintain a hashmap to store the frequency of elements 
          int n = nums.size();
          unordered_map<int, int>freq;
          for(int it : nums){
            freq[it]++;
          }

          // maintain a minHeap of size k
          // everytime it becomes more than k
          // pop() it
          // you'll left with the top k frequent elements
          priority_queue<freqPair, vector<freqPair>, greater<freqPair>>minHeap;

          // iterate the map
          // and maintain a minHeap size of k
          for(const auto &it : freq){
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k) minHeap.pop();
          }

         // extract all the K elements into a vector
         // note: priority_queue doesn't have iterators
          vector<int>ans;
          while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
          }

          return ans;

    }
};