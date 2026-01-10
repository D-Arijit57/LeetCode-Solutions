class Solution {

public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long minDiff = INT_MAX, ans = 0;

        for (int i = 0; i < n; i++) {

            int left = i + 1, right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {

                    return sum;

                }

                else if (sum > target) {

                    long long diff =(long long)(abs(sum - target)) ;

                    if (diff < minDiff) {

                        ans = sum;

                        minDiff = diff;
                    }

                    right--;

                }

                else {

                     long long diff = (long long)(abs(sum - target)) ;

                    if (diff < minDiff) {

                        ans = sum;

                        minDiff = diff;
                    }

                    left++;
                }
            }
        }

        return ans;
    }
};