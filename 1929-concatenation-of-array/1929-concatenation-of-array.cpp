#define v vector 
#define ll long long
class Solution {
public:
    v<int> getConcatenation(v<int>& nums) {
        int n = nums.size();
        v<int>ans;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(nums[i]);
        }
        for(int i = 0 ; i < n ; i++){
            ans.push_back(nums[i]);
        }
        return ans;   
    }
};