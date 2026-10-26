class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0], fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            // at any point if they meet
            if(slow == fast){
                // find the starting point
                slow = nums[0];

                // set slow to the start
                // move them by once place at a time
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