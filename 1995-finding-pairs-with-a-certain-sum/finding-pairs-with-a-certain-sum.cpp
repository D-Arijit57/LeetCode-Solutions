class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq; // frequency map for nums2
    
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        
        // Build frequency map for nums2
        for (int num : nums2) {
            freq[num]++;
        }
    }
    
    void add(int index, int val) {
        // Update frequency map: decrease count of old value
        freq[nums2[index]]--;
        if (freq[nums2[index]] == 0) {
            freq.erase(nums2[index]);
        }
        
        // Update nums2
        nums2[index] += val;
        
        // Update frequency map: increase count of new value
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int result = 0;
        
        // For each element in nums1, find how many elements in nums2 
        // can pair with it to sum to tot
        for (int num1 : nums1) {
            int target = tot - num1;
            if (freq.find(target) != freq.end()) {
                result += freq[target];
            }
        }
        
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */