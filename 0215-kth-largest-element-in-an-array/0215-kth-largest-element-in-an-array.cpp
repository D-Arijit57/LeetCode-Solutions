class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    // With a max-heap, the largest element is always at the top. So we can repeatedly remove the largest element until we reach the kth one.
       priority_queue<int>maxHeap;

       for(int num : nums){
            maxHeap.push(num);
       }

       for(int i = 1; i < k; i++){
            maxHeap.pop();
       }

       return maxHeap.top();
    }
};