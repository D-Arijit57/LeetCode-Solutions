class Solution {
public:
    string largestGoodInteger(string num) {
      string s = "";
      int i = 0;
      while(i+2 < num.length()){
          if(num[i] == num[i+1] && num[i+1] == num[i+2])
                break;
            i++;
      }
      if(i + 2 < num.length()){
          s = num.substr(i, 3);
          for(i = i + 3 ; i+2 < num.length() ; i++){
              if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                  if(num.substr(i,3) > s)
                      s = num.substr(i , 3);
                      i+=2;
              }
          }
      }
      return s;
    }
};