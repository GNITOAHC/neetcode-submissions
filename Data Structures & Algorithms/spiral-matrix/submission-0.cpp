class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        size_t s = matrix.size();
        vector<int> v;

        for (int i = 0; i <= (int)std::ceil((double)(matrix.size() / 2)); ++i) {
            const int top = i;
            const int bottom = s - 1 - i;
            const int left = i;
            const int right = matrix[i].size() - 1 - i;

            if (top > bottom || left > right) break;
            if (top == bottom) {
                for (int j = left; j <= right; ++j)
                    v.push_back(matrix[top][j]);
                break;
            }
            if (left == right) {
                for (int j = top; j <= bottom; ++j)
                    v.push_back(matrix[j][left]);
                break;
            }

            const int x = right - left + 1;
            const int y = bottom - top + 1;

            int counter = 0;
            while (counter < x) { // top left to top right
                v.push_back(matrix[top][left + counter]);
                ++counter;
            }
            
            counter = 1; // reset counter, first element was pushed
            while (counter < y) { // top right to bottom right
                v.push_back(matrix[top + counter][right]);
                ++counter;
            }
            
            counter = 1;
            while (counter < x) { // bottom right to bottom left
                v.push_back(matrix[bottom][right - counter]);
                ++counter;
            }

            counter = 1;
            while (counter < y - 1) { // bottom left to top left (top left is pushed already)
                v.push_back(matrix[bottom - counter][left]);
                ++counter;
            }
        }

        return v;
    }
};
