class Solution {
public:
    int maxNumberOfBalloons(string text) {
      if(text.size() < 7) return 0;
      int n = text.size();
      unordered_map<char,int>freq;
      // store the frequency of each character
      for(char c : text){
        freq[c]++;
      }

    // now we have the count of each character 
    // we can find the consumed resources 
    // and the one resource that runs out at first 
    // is the answer becasue its restricts to make entire token
    // for example if o : 3 -? we need two so freq['o'] / 2 = 1 
    // answer would be 1 since we can't make any further instances
    // of balloon using the character 'o'
    return min({
        freq['b'],
        freq['a'],
        freq['l']/2,
        freq['o']/2,
        freq['n']
    }) ;
    }
};