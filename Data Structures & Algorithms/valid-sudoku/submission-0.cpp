class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> v(27, vector<bool>(10, false));

        const int ROW = 0;
        const int COL = 9;
        const int GRP = 18;

        auto grp = [](int i, int j) -> int {
            return (i / 3) * 3 + (j / 3);
        };

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') continue;

                const int num = board[i][j] - '0';

                if (v[ROW + i][num]) return false;
                v[ROW + i][num] = true;

                if (v[COL + j][num]) return false;
                v[COL + j][num] = true;

                if (v[GRP + grp(i, j)][num]) return false;
                v[GRP + grp(i, j)][num] = true;
            }
        }

        return true;
    }
};
