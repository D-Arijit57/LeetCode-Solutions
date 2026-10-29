class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxHeap;

        for(int it : nums){
            maxHeap.push(it);
        }

        for(int i = 0 ; i < k - 1 ; i++){
            maxHeap.pop();
        }

        return maxHeap.top();
    }
};