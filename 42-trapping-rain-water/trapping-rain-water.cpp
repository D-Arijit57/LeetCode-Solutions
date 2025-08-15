class Solution {
public:
    int trap(vector<int>& height) {
        // two pointer approach
        int n = height.size();
        // base case if the array is empty return 0
        if(height.empty()) return 0;
        // initialize the two pointers 
        // one at the start and the other one at the end
        int res = 0 ,left = 0 , right = n - 1;

        // intitalize the max height for the both of the sides
        int leftMax = height[left] , rightMax = height[right];
        // run the loop until the two pointers meet/cross each other 
        while(left < right){
            //since we are trying to find the smaller height (as it holds the water)
            // move the pointer which has currently the smaller element from the side(left or right)
            // since the current height might be the new highest from the side( either right or left) 
            // update it before adding it to the result
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                res += leftMax - height[left];
            }
            else{
                right--;
                rightMax = max(rightMax , height[right]);
                res += rightMax - height[right];
            }
        }
        return res;
    }
};