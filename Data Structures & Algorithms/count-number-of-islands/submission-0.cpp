class Solution {
private:
    void explore(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int height = grid.size();
        int width = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();
            if (visited[y][x]) {
                continue;
            }
            visited[y][x] = true;
            if (grid[y][x] == '0') {
                continue;
            }
            if (x > 0) {
                q.push({y, x - 1});
            }
            if (x < width - 1) {
                q.push({y, x + 1});
            }
            if (y > 0) {
                q.push({y - 1, x});
            }
            if (y < height - 1) {
                q.push({y + 1, x});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(height, vector<bool>(width, false));

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (visited[i][j]) {
                    continue;
                }
                // visited[i][j] = true;
                if (grid[i][j] == '1') {
                    explore(grid, i, j, visited);
                    res++;
                }
            }
        }
        return res;
    }
};
