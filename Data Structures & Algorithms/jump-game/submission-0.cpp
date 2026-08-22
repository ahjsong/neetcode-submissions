class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJumps = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxJumps = max(maxJumps, nums[i]);
            maxJumps--;
            if (maxJumps < 0) {
                return false;
            }
        }
        return true;
    }
};
