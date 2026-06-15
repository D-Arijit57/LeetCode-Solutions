class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // two pointer approach 
        // brute force : take one interval and compare it with the rest of the list's interval O(N * M) N,M : size of the first and second list respectively
        // better approach : take i,j as two pointers from interval list 1 and 2 
        // compare them if the intersect then store the interval in the answer list 
        // if they don't then make sure to move the pointer which cannot intersect the other interval because since the array is sorted it won't intersect in future as well.
        // Time complexity : O(N+M)
            if(firstList.empty() || secondList.empty()) return {};
            int n = firstList.size();
            int m = secondList.size();
            vector<vector<int>>ans;
            int first = 0, second = 0;
            while(first < n && second < m){
                // initialize the lists
                vector<int>&a = firstList[first];
                vector<int>&b = secondList[second];

                int start = max(a[0],b[0]);
                int end = min(a[1], b[1]);

                if(start <= end){
                    ans.push_back({start, end});
                }

                // pointer movement
                // if a finishes first (cannot intersect)
                if(a[1] < b[1]){
                    first++;
                }
                // otherwise
                else second++;
            }

        return ans;
        }
};