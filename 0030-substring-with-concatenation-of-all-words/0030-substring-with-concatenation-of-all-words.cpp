class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        // frequency map for words
        unordered_map<string, int> target;
        for (string& s : words) {
            target[s]++;
        }
        int totalWords = words.size();
        int wordlen = words[0].length();
        int windowSize = wordlen * totalWords;
        int n = s.size();
        
        for (int offset = 0; offset < wordlen; offset++) {
            unordered_map<string, int> window;
            int left = offset;
            int cnt = 0;
            for (int right = offset; right + wordlen <= n; right+=wordlen) {
                string word = s.substr(right, wordlen);
                if (target.count(word)) {
                    window[word]++;
                    cnt++;

                    while (window[word] > target[word]) {
                        string leftWord = s.substr(left, wordlen);
                        window[leftWord]--;
                        left += wordlen;
                        cnt--;
                    }

                    if (cnt == totalWords) {
                        ans.push_back(left);
                    }
                } else {
                    window.clear();
                    cnt = 0;
                    left = right + wordlen;
                }
            }
        }
        return ans;
    }
};