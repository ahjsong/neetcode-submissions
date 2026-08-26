class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            int count = 0;
            for (int j = 0; j < ceil(log2(i + 1)); j++) {
                if ((1 << j) & i) {
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
