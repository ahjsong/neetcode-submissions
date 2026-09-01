class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool zero = false;
        int total = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (!zero && nums[i] == 0) {
                zero = true;
                continue;
            }
            total = total * nums[i];
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (zero) {
                if (nums[i] == 0) {
                    res.push_back(total);
                } else {
                    res.push_back(0);
                }
            } else {
                if (nums[i] == 0) {
                    res.push_back(total);
                } else {
                    res.push_back(total / nums[i]);
                }
            }
        }
        return res;
    }
};
