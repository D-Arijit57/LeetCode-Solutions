class Solution {
public:
    // function to calculate the next
    // % make sures we are inside a single cycle
    int getNext(int curr,vector<int>&nums){
        int n = nums.size();
        return ((curr + nums[curr]) % n + n ) % n ;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        // we need to use two loops 
        // outer loop for starting index 
        // while loop for cycle detection 
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0) continue;
            int slow = i, fast = i;
            // initial direction 
            int iniDir = nums[i];
            while(true){
                // before moving slow and fast check its direction
                // move only if its positive 
                if(nums[slow] * iniDir <= 0) break;
                if(nums[fast] * iniDir <= 0) break;
                // since fast moves two times check the next fast's direction
                int nextFast = getNext(fast,nums);
                if(nums[nextFast] * iniDir <= 0) break;
                slow = getNext(slow,nums);
                fast = getNext(nextFast,nums);
                // if slow and fast ever meets
                // make sure the current index doesn't have a self loop (invalid)
                if(slow == fast){
                    if(slow == getNext(slow,nums)) break;
                    else return true;
                } 
            }
            // since we aren't using any extra space (list or something)
            // make sure to mark the current index as 0 
            // since we don't need to calculate it again 
             int curr = i;
                while(nums[curr] * iniDir > 0){
                    int next = getNext(curr,nums);
                    nums[curr] = 0 ;
                    curr = next;
                }
        }
        return false;
    }
};