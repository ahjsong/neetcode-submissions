class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto val : nums) {
            if (seen.contains(val)) {
                return true;
            }
            seen.insert(val);
        }
        return false;
    }
};