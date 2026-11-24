class Solution {
public:
    // alias for pair
    typedef pair<int,int>diffPair;

    // custom comparator
    struct compare{
        bool operator() (const diffPair &a, const diffPair &b) const{
            // if the difference is equal
            // the smaller element survives
            if(a.first == b.first){
                return a.second < b.second;
            }
            // otherwise the smaller distance survives
            else return a.first < b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // edge case : if the array is empty
            if(arr.empty()) return {};

            // using a hashmap can cause us to lose duplicate elements
            // so push the pairs directly

            // define the maxHeap
            priority_queue<diffPair, vector<diffPair>, compare>maxHeap;

            // while prioritizing the maximum difference elements at the top
            // while maintaining a size of k 
            // it helps us to discard the k distant elements
            // and we are left with the k closest elements
            for(const auto &it : arr){
                // prioritize them by difference
                maxHeap.push({abs(x - it), it});
                if(maxHeap.size() > k) maxHeap.pop();
            }
            
            vector<int>ans;

            // extract the elements
            while(!maxHeap.empty()){
                // second - element
                ans.push_back(maxHeap.top().second);
                maxHeap.pop();
            }

            // sort the final answer
            sort(ans.begin(), ans.end());
            return ans;
    }
};