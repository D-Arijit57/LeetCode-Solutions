class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
         vector<bool> isBroken(26, false);//O(26)
        for (char ch : brokenLetters) {//O(brokenLetters.length())
            isBroken[ch - 'a'] = true;
        }

        int typedWordsCnt = 0;
        int brokenCnt=0;// number of broken alphabet in a word

        for(int i=0;i<text.size();i++){//O(text.length())
            if(text[i]==' '){
                if(brokenCnt==0){//we typed this word
                    typedWordsCnt++;
                }
                brokenCnt=0;
            }
            else if(isBroken[text[i]-'a']){
                brokenCnt++;
            }
        }
        // This is for the last word
        if(brokenCnt==0){
            typedWordsCnt++;
        }

        return typedWordsCnt;
    }
};