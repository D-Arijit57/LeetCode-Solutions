class Solution {
public:
    int getNext(int curr,vector<int>&nums){
        int n = nums.size();
        return ((curr + nums[curr]) % n + n ) % n ;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0) continue;
            int slow = i, fast = i;
            int iniDir = nums[i];
            while(true){
                if(nums[slow] * iniDir <= 0) break;
                if(nums[fast] * iniDir <= 0) break;
                int nextFast = getNext(fast,nums);
                if(nums[nextFast] * iniDir <= 0) break;
                slow = getNext(slow,nums);
                fast = getNext(nextFast,nums);
                if(slow == fast){
                    if(slow == getNext(slow,nums)) break;
                    else return true;
                }  
            }
            // mark 0 after failure
             int curr = i;
                while(nums[curr] == iniDir){
                    int next = getNext(curr,nums);
                    nums[curr] = 0 ;
                    curr = next;
                }
        }
        return false;
    }
};