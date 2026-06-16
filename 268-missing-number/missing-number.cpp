class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // for an array with size n 
        // the valid indices should 0,1..n (e.g :  n= 3, 0,1,2 are valid indices)
        // so for sure n+1 can't be an element for an array having the range 0 to n
        // we can use cylic sort here to place all the elements in its correct place 
        // after that we can recheck to verify if every element is at the correct place or not index wise 
        // the index which is missing the correct element is the element that is missing from the array 
        // since for a range of 0 to n , correctIndex = nums[i]
        int n = nums.size();
        int i = 0 ;
        // sort it up using cyclic sort
        while(i < n){
           int correctIndex = nums[i];
           // only place the numbers that have a valid index inside the array 
            if(nums[i] < n && nums[i] != nums[correctIndex]){
                swap(nums[i],nums[correctIndex]);
            }
            else i++;
        }
        // recheck for finding out the missing element
        for(int i = 0 ; i < n ; i++){
            if(i != nums[i]){
                return i;
            }
        }
        // if all positions are correct then n is missing
        return n;
    }
};