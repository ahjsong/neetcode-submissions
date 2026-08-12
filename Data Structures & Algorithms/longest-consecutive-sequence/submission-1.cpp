class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> myset(nums.begin(), nums.end());

        int maxVal = 0;
        unordered_set<int> seen;
        for (const auto& val : myset) {
            int counter = 0;
            int current = val;
            if (seen.count(current)) {
                continue;
            }

            while (myset.count(current - 1)) {
                current -= 1;
            }

            while (myset.count(current)) {
                counter++;
                current++;
                seen.insert(current);
            }
            maxVal = max(maxVal, counter);
        }

        return maxVal;
    }
};
