class Solution {
public:
    bool isValid(string word) {
        // Check minimum length
        if (word.length() < 3) {
            return false;
        }
        
        // Define vowels (both lowercase and uppercase)
        string vowels = "aeiouAEIOU";
        
        // Flags to track if we found vowel and consonant
        bool has_vowel = false;
        bool has_consonant = false;
        
        // Check each character
        for (char c : word) {
            // Check if character is valid (only digits and English letters)
            if (!isdigit(c) && !isalpha(c)) {
                return false;
            }
            
            // If it's a letter, check if it's vowel or consonant
            if (isalpha(c)) {
                if (vowels.find(c) != string::npos) {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            }
        }
        
        // Must have at least one vowel and one consonant
        return has_vowel && has_consonant;
    }
};