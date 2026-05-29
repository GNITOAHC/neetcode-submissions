class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                // start bfs if encounter any island
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++count;
                }
            }
        }

        return count;
    }
private:
    // bfs will turn the encountered island to 2
    void bfs(vector<vector<char>>& grid, int i, int j) {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '2';

        cout << i << ' ' << j << endl;

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
                q.push({i + 1, j});
                grid[i + 1][j] = '2';
            }
            if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                q.push({i - 1, j});
                grid[i - 1][j] = '2';
            }
            if (j + 1 < grid[i].size() && grid[i][j + 1] == '1') {
                q.push({i, j + 1});
                grid[i][j + 1] = '2';
            }
            if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                q.push({i, j - 1});
                grid[i][j - 1] = '2';
            }
        }
    }
};
