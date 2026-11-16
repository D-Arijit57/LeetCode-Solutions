class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // for each intervals check if they overlap
        // there can be only an intersection possible if they overlap
        // if they do 
        // 1. second.start <= first.end
        // intersection becomes {first.end, second.start}
        // 2. second start > first.end ( no overlap, no intersection)

        // the above condition would work only if there is one list
        // since there are two lists
        // the above condition doesn't cover the case 
        // where an interval from list A consumes an entire interval from list B
        // A =[5,10], B= [1,3]

        // so we use max(A.start, B.Start) <= min(A.end, B.end)
        // it handles both directions and also includes touching points
        int n = firstList.size();
        int m = secondList.size();

        // if any of them is empty then there can be no intersections possible
        if(n == 0 || m == 0) return {};
        vector<vector<int>>ans;
        int i = 0, j = 0;
        // iterate the first list
        while(i < n && j < m){
            
            // check overlap
            // an interval would exist if 
            // B starts before A ends or A ends before B ends
            // we can express that using this:
            // max(a.start,b.start) <= min(a.end,b.end)
            if(max(firstList[i][0],secondList[j][0]) <= min(firstList[i][1], secondList[j][1])){
                // consider two lists : firstList = [[a,b], ...], secondList = [[c,d],...]
                // the intersection is : e.g [[0,2],...], [[1,5],...] 
                // intersection would be {{1,2},...}
                // {max(a,c), min(b,d)}
                int start = max(firstList[i][0],secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]);
                ans.push_back({start,end});  
            }
            // move the pointers for each of the list if they don't overlap with each other
            // since they are sorted
            // if one interval from a list currently doesn't overlap with the other 
            // no way it's going to overal 
            // so advance pointers which endes earlier
            firstList[i][1] > secondList[j][1] ? j++ : i++;
        }
        return ans;
        
    }
};  