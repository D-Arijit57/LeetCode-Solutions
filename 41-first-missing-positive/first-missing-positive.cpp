class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // the range is not given here so we need to define the range
        // if we observe every possible answer belongs to the range [1,n+1]
        // e.g [0,1,2] the answer is n+1 that is 3
        // e.g [7,8,9,10,11] the answer is 1
        // therefore 1 <= answer <= n+1
        // so if somehow we can make sure normalize this range for every test
        // case it becomes simple cyclic sort problem where we would place
        // number in its correct index (i.e value x at index x-1) and we can
        // just find the first anomaly that is the first missing positive
        int n = nums.size();
        int i = 0;
        // cyclic sort
        while (i < n) {

            if (nums[i] > 0 && nums[i] <= n) {

                int correctIndex = nums[i] - 1;

                if (nums[i] != nums[correctIndex]) {
                    swap(nums[i], nums[correctIndex]);
                    continue;
                }
            }

            i++;
        }
        // re-check
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};