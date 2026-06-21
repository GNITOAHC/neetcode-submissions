class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        using ele = pair<int, pair<int, int>>;
        priority_queue<ele, vector<ele>, greater<ele>> q; // {dis, {pos}}

        // find all treasure first
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == 0) q.push({0, {i, j}});
        }

        // define direction
        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [dis, pos] = q.top();
            q.pop();
            const int i = pos.first, j = pos.second;

            for (int d = 0; d < 4; ++d) {
                const int dir_x = i + x[d], dir_y = j + y[d];
                if (dir_x < 0 || grid.size() <= dir_x
                    || dir_y < 0 || grid[dir_x].size() <= dir_y) {
                    continue;        
                }
                if (grid[dir_x][dir_y] == -1) continue;
                if (grid[dir_x][dir_y] < dis + 1) continue;
                grid[dir_x][dir_y] = dis + 1;
                q.push({dis + 1, {dir_x, dir_y}});
            }
        }

        return;
    }
};
