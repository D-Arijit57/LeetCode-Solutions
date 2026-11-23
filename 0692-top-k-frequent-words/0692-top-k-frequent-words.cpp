class Solution {
public:
    // alias for pair
    typedef pair<int, string>freqPair;

    // custom comparator
    // why we would need this ? 
    // e.g a = {2,"apple"}, b = {2,"banana"} 
    // because the deault minHeap greater<int> keeps the strings based on the frequency
    // it would keep apple at the top
    // and apple instead banana would get poped()
    // but we need to keep the lexicographically smaller one if the frequency ties
    struct compare{ // first = freq, second = word
        bool operator()(const freqPair &a, const freqPair &b) const{
            // if the freuquency tie
            // remove the word that is the largest (lexicographically)
            if(a.first == b.first){
                // we need to keep in our mind that its a min heap
                // means that its top stores the lowest freq element
                // so a > b would be a reverse condition for it
                // e.g a = {2,"apple"}, b = {2,"banana"}
                // we want to remove the lexicographically larger word here which is b
                // so a < b
                // apple < banana "true"
                // apple > banana "false"
                // so banana gets moved to the top of the queue
                return a.second < b.second;
            }

            // otherwise remove the word with the lowest frequency
            else return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(words.empty()) return {};

        // record the frequency
        unordered_map<string, int>freq;
        for(const auto &word : words){
            freq[word]++;
        }

        // define a minHeap
        // adding the customer comparator : "compare"
        priority_queue<freqPair, vector<freqPair>, compare>minHeap;

        // maintain a size of k
        for(const auto &it : freq){
            // it.second : int (frequency), it.first : string
            // maintain the order of the pair < int, string>
            minHeap.push({it.second, it.first});
            // top gets removed
            if(minHeap.size() > k) minHeap.pop();
        }

        vector<string>ans;
        // extract the top k frequent strings
        while(!minHeap.empty()){
            // minHeap stores : {int, string}
            // extract the string through .second
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // revserse it
        // our comparator ensures that the least desirable element stays at the top so that we can remove it whenever the heap size exceeds k.
        // But this also means extraction happens in the opposite order from the required answer.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};