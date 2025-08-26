class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       int maxDS = 0;
       int maxArea = 0;

       for(int i = 0 ; i < dimensions.size() ; i++){
        int len = dimensions[i][0];
        int width = dimensions[i][1];

        int DS = len * len + width * width;
        int area = len * width;

        if(DS > maxDS || (DS == maxDS && area > maxArea)){
            maxDS = DS;
            maxArea = area;
        }
        
       }
            
       return maxArea; 
    }
};