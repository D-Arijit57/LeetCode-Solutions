class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size()) return false;
        // update the frequencies for ransomeNote and magazine
        // the character in the ransomNote should have a frequency
        // character_in_ransomNote >= character_in_magazine
        unordered_map<char,int>ransomNoteFreq;
        unordered_map<char,int>magazineFreq;
        // update the frequency of characters from the ransomNote 
        for(char c : ransomNote){
            ransomNoteFreq[c]++;
        }

        //update the frequency of characters from the magazine
        for(char c : magazine){
            magazineFreq[c]++;
        }

        for(const auto& it : ransomNoteFreq){
            // check if the count is sufficient for the ransomNote
            if(magazineFreq[it.first] < it.second) return false;
        }
        return true;
    }
};