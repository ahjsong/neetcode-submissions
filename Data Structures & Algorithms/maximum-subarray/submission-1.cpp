class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -10000;
        int maxSum = -10000;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum = max(sum, nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
