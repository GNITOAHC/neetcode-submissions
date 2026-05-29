class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) // is island
                    max_area = std::max(max_area, bfs(grid, i, j));
            }
        }

        return max_area;
    }
private:
    int bfs(vector<vector<int>>& grid, int i, int j) {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;

        int area = 0;

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            ++area;

            if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
                q.push({i + 1, j});
                grid[i + 1][j] = -1;
            }
            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                q.push({i - 1, j});
                grid[i - 1][j] = -1;
            }
            if (j + 1 < grid[i].size() && grid[i][j + 1] == 1) {
                q.push({i, j + 1});
                grid[i][j + 1] = -1;
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                q.push({i, j - 1});
                grid[i][j - 1] = -1;
            }
        }

        return area;
    }
};
