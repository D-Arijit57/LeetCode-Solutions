class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // According to pigeon hole principle if there are n holes and n+1 pigeons
        // atleast 1 hole will contain more than 1 pigeon
        // so for sure in this case a duplicate will exist
        int n = nums.size();
        int slow = nums[0], fast = nums[0];

        // using floyd's cycle detection 
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            // if they ever meet, find out the starting point
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