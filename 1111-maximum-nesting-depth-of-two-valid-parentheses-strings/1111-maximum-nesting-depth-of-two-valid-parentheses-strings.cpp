class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer;
        int currentGroup = 1;

        for (char bracket : seq) {
            if (bracket == '(') {
                answer.push_back(1 - currentGroup);
            } else {
                answer.push_back(currentGroup);
            }

            currentGroup ^= 1;
        }

        return answer;
    }
};