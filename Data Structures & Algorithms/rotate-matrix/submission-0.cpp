class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t s = matrix.size();
        for (int i = 0; i <= (int)std::ceil((float)(s/2)); ++i) {
            const int fixed_top = i;
            const int fixed_btm = s - 1 - i;
            const int fixed_left = i;
            const int fixed_rght = s - 1 - i;
            
            if (fixed_top >= fixed_btm) break;
            
            for (int j = 0; j < fixed_btm - fixed_top; ++j) {
                const int last = matrix[fixed_btm - j][fixed_left];
                matrix[fixed_btm - j][fixed_left] = matrix[fixed_btm][fixed_rght - j];
                matrix[fixed_btm][fixed_rght - j] = matrix[fixed_top + j][fixed_rght];
                matrix[fixed_top + j][fixed_rght] = matrix[fixed_top][fixed_left + j];
                matrix[fixed_top][fixed_left + j] = last;
            }
        }
    }
};
