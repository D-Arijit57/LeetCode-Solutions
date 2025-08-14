class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n - 1, maxarea = 0;
        while(left < right){
            int width = right - left;
            int minheight = min(height[left],height[right]);
            int area = minheight * width;
            maxarea = max(area, maxarea);

            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxarea;
    }
};