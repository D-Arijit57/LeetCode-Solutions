class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // According to pigeon hole principle
        // if there are {1,n} holes and n+1 pigeons atleast one hole should contain two pigeons
        // so here atleast one number will repeat since it has a total n+1 integers but the range given is {1,n} (i.e only n places)
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