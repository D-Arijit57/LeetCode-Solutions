class Solution {
public:
    // calculate the getNext
    int getNext(vector<int>&nums,int curr){
        int n = nums.size();
        return ((curr+nums[curr]) % n + n ) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0) continue;
            int slow = i, fast = i;
            int dir = nums[i];
            while(true){
                // check direction before moving slow and fast
                // direction logic -
                // if direction is same (both positive / both negative) then the product will be positive
                if(dir * nums[slow] <= 0) break;
                slow = getNext(nums,slow);
                if(dir * nums[fast] <= 0) break;
                int getNextFast = getNext(nums,fast);
                if(dir * nums[getNextFast] <= 0) break;
                fast = getNext(nums,getNextFast);

                // if slow and fast ever meet
                if(slow == fast){
                    // check for the self loops
                    if(slow == getNext(nums,slow)) break;
                    else return true;
                }
            }
            // marking all the invalid paths as 0
            // so that we don't check them again
            // since its  unecessary overhead for re-checking 
            int curr = i ;
            while(dir * nums[curr] > 0){
                nums[curr] = 0;
                curr = getNext(nums,curr);
            }
        }
        return false;
    }
};