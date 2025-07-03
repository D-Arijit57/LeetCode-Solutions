class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.length() < k) {
            int size = word.length();
            for (int i = 0; i < size; i++) {
                char nextChar = 'a' + ((word[i] - 'a' + 1) % 26);
                word += nextChar;
            }
        }
        return word[k - 1]; // to return the char at position 5 (0 base indexing)
    }
};