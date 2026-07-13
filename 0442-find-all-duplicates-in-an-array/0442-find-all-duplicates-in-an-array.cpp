class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // place the elements in its correct place
        // the ones which are mistplaced are the duplicates
        int n = nums.size();
        vector<int>duplicates;
        // 1. place the elements in its correct place
        int i = 0;
        while(i<n){
            // value x belongs to x - 1
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]){
                swap(nums[i],nums[correctIndex]);
            }
            // we can't move forward until the current number in its correct place
            else i++;
        }

        // 2. re-iterate and check if everything's at the right place
        // the ones occupying the wrong index are the duplicates
        // add them to the answer array
        for(int i = 0 ; i < n ; i++){
            // check if the value x is at the index to x-1
            // e,g : 0->1 , 1->2, 2->3 
        if(nums[i] - 1 != i ) duplicates.push_back(nums[i]);
        }
        return duplicates;
    }
};