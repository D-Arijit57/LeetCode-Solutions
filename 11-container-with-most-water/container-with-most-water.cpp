class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        // two pointer apporach 
        // one from the start and one from the end 
        int left = 0 , right = n - 1, maxarea = 0;
        while(left < right){
            // calculate the distance between two heights
            int width = right - left;
            // since the min height decides the capacity 
            // calculate the min heeight
            int minheight = min(height[left],height[right]);
            // update the maxarea if needed (if the new one is larger)
            int area = minheight * width;
            maxarea = max(area, maxarea);

            // if the height in the left is smaller than right 
            // find the larger one 
            // since the smaller height decides the capacity 
            // moving the pointer (from the end) might find us a greater element
            // contributing to a larger area despite the smaller width
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxarea;
    }
};