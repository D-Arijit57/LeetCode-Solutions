class Solution {
public:
    int strStr(string haystack, string needle) {
      for(int i = 0 ; i<haystack.size() ; i++){
          if(haystack[i] == needle[0]){
              bool total = true;
              for(int j = 0 ; j<needle.size() ; j++){
                  if(needle[j] != haystack[i+j]){
                      total = false;
                      break;
                  }
              }
              if(total == true ) return i;
          }
      }
      return -1;
    }
};