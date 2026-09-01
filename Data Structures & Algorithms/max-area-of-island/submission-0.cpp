class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int height = grid.size();
        int width = grid[0].size();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, bfs(grid, i, j));
                }
            }
        }
        return res;
    }

    int bfs(vector<vector<int>>& grid, int j, int i) {
        int total = 0;
        int height = grid.size();
        int width = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (grid[y][x] == 0) {
                continue;
            }
            total++;
            grid[y][x] = 0;
            if (x > 0) {
                q.push({x - 1, y});
            }
            if (x < width - 1) {
                q.push({x + 1, y});
            }
            if (y > 0) {
                q.push({x, y - 1});
            }
            if (y < height - 1) {
                q.push({x, y + 1});
            }
        }
        return total;
    }
};
