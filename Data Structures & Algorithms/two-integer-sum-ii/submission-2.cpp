class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum < target) {
                left++;
                // while (numbers[left] == numbers[right]) {
                //     left++;
                // }
            } else if (sum > target) {
                right--;
                // while (numbers[left] == numbers[right]) {
                //     right--;
                // }
            } else {
                return {left + 1, right + 1};
            }
        }
    }
};
