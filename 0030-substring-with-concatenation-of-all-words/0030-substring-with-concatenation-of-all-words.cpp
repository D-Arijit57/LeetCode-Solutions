#define v vector
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        v<int> ans;

        // we have to check for word frequency
        // since a word should exactly appear once in the substring
        // frequency map for the words
        unordered_map<string, int> targetFreq;
        for (string& s : words) {
            targetFreq[s]++;
        }

        int n = s.size();
        int wordlen = words[0].length();
        int totalWords = words.size();
        for (int offset = 0; offset < wordlen; offset++) {
            int left = offset;
            int cnt = 0;
            unordered_map<string, int> windowFreq;
            for (int right = offset; right + wordlen <= n; right += wordlen) {
                string word = s.substr(right, wordlen);

                if (targetFreq.count(word)) {
                    windowFreq[word]++;
                    cnt++;
                    while (windowFreq[word] > targetFreq[word]) {
                        string leftWord = s.substr(left, wordlen);
                        windowFreq[leftWord]--;
                        left += wordlen;
                        cnt--;
                    }

                    if (cnt == totalWords) {
                        ans.push_back(left);
                    }

                } else {
                    windowFreq.clear();
                    cnt = 0;
                    left = right + wordlen;
                }
            }
        }
        return ans;
    }
};