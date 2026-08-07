class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int left = 0;
        int right = heights.size() - 1;
        while (left < right) {
            int currArea = (right - left) * min(heights[left], heights[right]);
            area = max(area, currArea);

            if (heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return area;
    }
};
