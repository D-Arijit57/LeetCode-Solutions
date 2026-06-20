// Rev 20th June : 
// Mistakes : 
// 1. Forgot the invariant, which regions defines what which cause the confused pointer movements 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = n - 1;
        int mid = left;
        while(mid <= right){
            // if the color is white do nothing move forward since 1 should be in the middle
            if(nums[mid] == 1) mid++;
            // if the color is red then swap it up with the left, since it should be at the left
            // according to the invariant we know that from left...mid-1 we got only 1s
            // so the element swapped with left is 1 only so we can safely move left and mid together
            else if(nums[mid] == 0){
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }
            // if the color is blue then swap it up with the right, since it should be at the right
            // according to the invariant mid-1...right is unknown
            // so we don't what got from the right when we swapped so we must check that before moving both mid and right
            else{
                swap(nums[right], nums[mid]);
                right--;
            }
         
        }
        
    }
};