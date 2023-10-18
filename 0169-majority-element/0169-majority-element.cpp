class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using moore's voting algorithm
        int el; // elements
        int cnt = 0 ; // counter
        int n = nums.size(); //size of the array 

        // applying the algorithm 
        for(int i = 0 ; i<n ; i++){
            if(cnt == 0){ // if the count becomes 0 
             el = nums[i]; // make the current element the majority element
                cnt = 1; // and set count as 0
            }
            else if(nums[i] == el) cnt++; // if its the element increase the count 
            else cnt--; // if its not the element decrease the count 
        }
        // now check if the number is actually the majority element by comparing the element's total frequency throughout the array with (n/2)
        int cnt1 = 0;
        for(int i = 0 ; i<n ; i++){
            if(nums[i] == el) cnt1++;
        }
    if(cnt1 > (n/2)) return el;
    return -1;
 }
};