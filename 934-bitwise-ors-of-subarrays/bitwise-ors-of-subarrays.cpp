class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> current;
        
        for (int num : arr) {
            unordered_set<int> next;
            // Start a new subarray with just the current number
            next.insert(num);
            
            // Extend all existing subarrays by ORing with current number
            for (int prev : current) {
                next.insert(prev | num);
            }
            
            // Add all OR values ending at current position to result
            for (int val : next) {
                result.insert(val);
            }
            
            current = next;
        }
        
        return result.size();
    }
};