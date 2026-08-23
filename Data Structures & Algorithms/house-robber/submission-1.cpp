class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return nums[0];
        }
        int memo[n];
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }
        return memo[n - 1];
    }
};
