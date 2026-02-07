class Solution {
public:
    int getNext(vector<int>&nums, int curr){
        int n = nums.size();
        return ((curr+nums[curr]) % n + n) % n; 
    }
    bool circularArrayLoop(vector<int>& nums) {
        // Loop detection + direction sense       
        // i -> each node 
        // nums[i] -> number of steps to jump
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 0) continue;
            int dir = nums[i];
            int slow = i, fast = i;
            // if at any point the direction becomes negative 
            // since there is no point to check the direction if the loop is going to be invalid
            // due to opposite direction
           while(true){
            // check all at once if one of them has a opposite direction 
            if(nums[slow] * dir <= 0) break;
            if(nums[fast] * dir <= 0) break;
            int nextFast = getNext(nums,fast);
            if(nums[nextFast] * dir <= 0) break;
            
            // move fast and slow 
            slow = getNext(nums,slow);
            fast = getNext(nums,getNext(nums,fast));

           // if slow and fast ever meet
            if(slow == fast) {
                // check for the self loop first
                if(slow == getNext(nums,slow)) break;
                else return true ;
              }
           }
            // marking all the paths as zero which are invalid
            int curr = i;
            while(nums[curr] * dir > 0){
                int next = getNext(nums,curr);
                nums[curr] = 0;
                curr = next;
            }
        }
    return false ;
    }
};