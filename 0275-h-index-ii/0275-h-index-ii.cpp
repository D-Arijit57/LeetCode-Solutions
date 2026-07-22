class Solution {
public:
    bool doesHaveCitations(vector<int>&citations, int h){
        int n = citations.size();
        int cnt = 0;
        // if for that specific h we have enough number of cited papers
        // the value of h works so we try to find a greater value that works for it 
        for(int i = 0 ; i < n ; i++){
            if(citations[i] >= h){
                cnt++;
            }
        }
        return cnt >= h;
    }
    int hIndex(vector<int>& citations) {
        // we are asked to find the maximum value h such that
        // in citations it has atleast h papers with h citations 
        // search space belongs from the 0 to n
        // n : total number of papers
        int low = 0;
        // h index can never the large than the total number of papers 
        int high = citations.size();
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // if this h already does have the required citations
            // then check for a larger one
            if(doesHaveCitations(citations,mid)){
                ans = mid;
                low = mid + 1;
            }
            // if it doesn't satisfy look for a smaller h 
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};