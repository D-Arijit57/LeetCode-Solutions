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
        // preprocessing
        int n = s.size();
        int wordlen = words[0].length();
        int totalWords = words.size();

        // setting the offset
        for (int offset = 0; offset < wordlen; offset++) {
            int left = offset;
            int cnt = 0;
            unordered_map<string, int> windowFreq;
            // Inner sliding window 
            for (int right = offset; right + wordlen <= n; right += wordlen) {
                // extract the word
                string word = s.substr(right, wordlen);
                // if the word exists inside the target 
                // increase the count as well as the frequency inside the window
                if (targetFreq.count(word)) {
                    windowFreq[word]++;
                    cnt++;
                    // we don't need more words since one word should extacly appear once 
                    // invariant -> windowFreq[word] <= targetFreq[word]
                    while (windowFreq[word] > targetFreq[word]) {
                        string leftWord = s.substr(left, wordlen);
                        windowFreq[leftWord]--;
                        left += wordlen;
                        cnt--;
                    }
                    // if the count becomes equal to the totalwords
                    // we have hit a valid substring (exact number of words)
                    if (cnt == totalWords) {
                        ans.push_back(left);
                    }

                } else { // if the word doesn't exist its a invalid sequence 
                // so reset the cnt as well as set the left to the starting of another sequence
                    windowFreq.clear();
                    cnt = 0;
                    left = right + wordlen;
                }
            }
        }
        return ans;
    }
};