class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        unordered_set<int> is;
        unordered_set<int> js;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] == 0) {
                    is.insert(i);
                    js.insert(j);
                }
            }
        }

        for (const auto& val : is) {
            for (int i = 0; i < width; i++) {
                matrix[val][i] = 0;
            }
        }

        for (const auto& val : js) {
            for (int i = 0; i < height; i++) {
                matrix[i][val] = 0;
            }
        }
    }
};
