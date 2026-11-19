class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     // using a minHeap approach
     priority_queue<int, vector<int>, greater<int>>minHeap;

    // we maintain a minHeap size of k 
    // and since it restructures itself after every push
    // the smallest element is at the top
    // so if we maintain a size of k
    // and pop it out after every push that makes the size > k
    // the element we are left with are the K largest elements in the array
    // as we are popping out the k smallest elements by the end of iteration
     for(const int &it : nums){
        minHeap.push(it);
        if(minHeap.size() > k) minHeap.pop();
     }
     return minHeap.top();
    }
};