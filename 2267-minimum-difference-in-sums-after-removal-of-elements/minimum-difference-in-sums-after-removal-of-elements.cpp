class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        
        // For each position i, calculate:
        // minLeft[i] = minimum sum of n elements from nums[0...i]
        // maxRight[i] = maximum sum of n elements from nums[i...3*n-1]
        
        vector<long long> minLeft(3 * n);
        vector<long long> maxRight(3 * n);
        
        // Calculate minLeft array
        // Use a max heap to keep track of the n smallest elements
        priority_queue<int> maxHeap;
        long long sum = 0;
        
        for (int i = 0; i < 3 * n; i++) {
            maxHeap.push(nums[i]);
            sum += nums[i];
            
            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            
            if (maxHeap.size() == n) {
                minLeft[i] = sum;
            }
        }
        
        // Calculate maxRight array
        // Use a min heap to keep track of the n largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        
        for (int i = 3 * n - 1; i >= 0; i--) {
            minHeap.push(nums[i]);
            sum += nums[i];
            
            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            
            if (minHeap.size() == n) {
                maxRight[i] = sum;
            }
        }
        
        // Find minimum difference
        long long minDiff = LLONG_MAX;
        
        // Try all possible split points
        // The first part ends at position i, second part starts at i+1
        for (int i = n - 1; i < 2 * n; i++) {
            minDiff = min(minDiff, minLeft[i] - maxRight[i + 1]);
        }
        
        return minDiff;
    }
};