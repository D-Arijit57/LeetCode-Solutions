class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // if there are n + 1 numbers in n size of array [1,n] inclusive
        // atleast one place have duplicate number or it'll have atleast one duplicate
        // pigeon hole principle
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            // if they meet somewhere means that we are inside the cycle
            // and to find the start that is the missing number set slow to the start
            // and move fast and slow by one place
            if(slow == fast){
                slow = nums[0];
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return -1;
    }
};