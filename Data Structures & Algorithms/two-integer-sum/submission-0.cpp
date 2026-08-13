class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); i++) {
            if (mymap.contains(nums[i])) {
                return {min(i, mymap[nums[i]]), max(i, mymap[nums[i]])};
            }
            mymap[target - nums[i]] = i;
        }
        return {0, 0};
    }
};
