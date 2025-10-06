class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {       int maxFreq = 0;
        int total = 0;
        unordered_map<int, int>mpp; // using a map t
        // key -> element , value -> frequency
        for(int num : nums){
            mpp[num]++;
            if(mpp[num] > maxFreq) maxFreq = mpp[num];
        }
        
        
        for(auto& [key,value] : mpp){
            if(value == maxFreq){
                total += value ;
            }
        }
        return total;
    }
};