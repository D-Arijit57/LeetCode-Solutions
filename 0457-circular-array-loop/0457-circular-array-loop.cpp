class Solution {
public:
    int getNext(vector<int>& nums, int curr) {
        int n = nums.size();
        return ((curr + nums[curr]) % n + n) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            // already processed paths
            if (nums[i] == 0)
                continue;

            bool forward = nums[i] > 0;
            int slow = i, fast = i;

            // Floyd's cycle detection
            while (true) {
                int next_slow = getNext(nums, slow);
                if ((nums[next_slow] > 0) != forward)
                    break;
                int next_fast = getNext(nums, fast);
                if ((nums[next_fast] > 0) != forward)
                    break;
                next_fast = getNext(nums, next_fast);
                if ((nums[next_fast] > 0) != forward)
                    break;

                slow = next_slow;
                fast = next_fast;

                // if slow and fast meets
                if (slow == fast) {
                    // if self-loop length = 1
                    if (slow == getNext(nums, slow))
                        break;

                    return true;
                }
            }
            // no valid cycle found from i
            // mark all nodes in this path as visited
            int curr = i;
            while ((nums[curr] > 0) == forward) {
                int nxt = getNext(nums, curr);

                nums[curr] = 0;

                if (nxt == curr)

                    break;

                curr = nxt;
            }
        }
        return false;
    }
};