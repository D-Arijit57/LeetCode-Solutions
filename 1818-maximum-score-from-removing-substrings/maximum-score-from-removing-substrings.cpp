class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalPoints = 0;
        
        // Strategy: Always remove the more valuable substring first
        // This greedy approach gives us the maximum possible points
        if (x >= y) {
            // "ab" is worth more, so remove it first, then "ba"
            string afterRemovingAB = removeSubstring(s, "ab", x, totalPoints);
            removeSubstring(afterRemovingAB, "ba", y, totalPoints);
        } else {
            // "ba" is worth more, so remove it first, then "ab"  
            string afterRemovingBA = removeSubstring(s, "ba", y, totalPoints);
            removeSubstring(afterRemovingBA, "ab", x, totalPoints);
        }
        
        return totalPoints;
    }
    
private:
    // Removes all instances of targetSubstring and updates the total points
    string removeSubstring(string text, string targetSubstring, int pointsPerRemoval, int& totalPoints) {
        string resultAfterRemovals = "";
        
        // Process each character one by one
        for (char currentChar : text) {
            // Add the current character to our result
            resultAfterRemovals += currentChar;
            
            // Check if we just formed the target substring at the end
            int resultLength = resultAfterRemovals.length();
            if (resultLength >= 2) {
                string lastTwoChars = resultAfterRemovals.substr(resultLength - 2, 2);
                
                if (lastTwoChars == targetSubstring) {
                    // Found the target! Remove it and add points
                    resultAfterRemovals.pop_back(); // Remove second character
                    resultAfterRemovals.pop_back(); // Remove first character
                    totalPoints += pointsPerRemoval;
                }
            }
        }
        
        return resultAfterRemovals;
    }
};

// Here's a cleaner version that's even more intuitive:
class SolutionCleaner {
public:
    int maximumGain(string s, int x, int y) {
        // Figure out which operation is more profitable
        bool removeABFirst = (x >= y);
        
        if (removeABFirst) {
            return removeABThenBA(s, x, y);
        } else {
            return removeBAThenAB(s, x, y);
        }
    }
    
private:
    int removeABThenBA(string s, int abPoints, int baPoints) {
        int totalScore = 0;
        
        // First pass: greedily remove all "ab" substrings
        string afterABRemoval = greedyRemove(s, 'a', 'b', abPoints, totalScore);
        
        // Second pass: greedily remove all "ba" substrings from what's left
        greedyRemove(afterABRemoval, 'b', 'a', baPoints, totalScore);
        
        return totalScore;
    }
    
    int removeBAThenAB(string s, int abPoints, int baPoints) {
        int totalScore = 0;
        
        // First pass: greedily remove all "ba" substrings
        string afterBARemoval = greedyRemove(s, 'b', 'a', baPoints, totalScore);
        
        // Second pass: greedily remove all "ab" substrings from what's left
        greedyRemove(afterBARemoval, 'a', 'b', abPoints, totalScore);
        
        return totalScore;
    }
    
    // This function acts like a stack - when we see firstChar followed by secondChar,
    // we "remove" them (like they cancel out) and add points
    string greedyRemove(string text, char firstChar, char secondChar, int pointsPerPair, int& totalScore) {
        string stack = "";
        
        for (char ch : text) {
            stack += ch;
            
            // Check if we just completed a pair we want to remove
            int stackSize = stack.size();
            if (stackSize >= 2 && 
                stack[stackSize - 2] == firstChar && 
                stack[stackSize - 1] == secondChar) {
                
                // Remove the pair and add points (like they cancelled out)
                stack.pop_back();
                stack.pop_back();
                totalScore += pointsPerPair;
            }
        }
        
        return stack;
    }
};