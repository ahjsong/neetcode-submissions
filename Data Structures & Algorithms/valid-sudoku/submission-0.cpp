class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {};
        bool col[9][9] = {};
        unordered_set<int> sets[3][3];

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int value = board[i][j] - '1';
                if (row[i][value] || col[j][value]) {
                    return false;
                }
                row[i][value] = true;
                col[j][value] = true;

                int sqRow = i / 3;
                int sqCol = j / 3;
                if (sets[sqRow][sqCol].count(value)) {
                    return false;
                }
                sets[sqRow][sqCol].insert(value);
            }
        }
        return true;
    }
};
