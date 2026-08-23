class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (calculateRoute(j, i, heights)) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    bool calculateRoute(int x, int y, vector<vector<int>>& heights) {
        set<pair<int, int>> visited;
        int height = heights.size() - 1;
        int width = heights[0].size() - 1;
        bool pacific = false;
        bool atlantic = false;

        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();
            if (visited.count({currX, currY})){ 
                continue;
            }
            visited.insert({currX, currY});

            if (currX == 0 || currY == 0) {
                pacific = true;
            }
            if (currX == width || currY == height) {
                atlantic = true;
            }
            if (pacific && atlantic){ 
                return true;
            }
            
            if (currX > 0) {
                if (heights[currY][currX - 1] <= heights[currY][currX]) {
                    q.push({currX - 1, currY});
                }
            }
            if (currX < width) {
                if (heights[currY][currX + 1] <= heights[currY][currX]) {
                    q.push({currX + 1, currY});
                }
            }
            if (currY > 0) {
                if (heights[currY - 1][currX] <= heights[currY][currX]) {
                    q.push({currX, currY - 1});
                }
            }
            if (currY < height) {
                if (heights[currY + 1][currX] <= heights[currY][currX]) {
                    q.push({currX, currY + 1});
                }
            }
        }
        return false;
    }
};
