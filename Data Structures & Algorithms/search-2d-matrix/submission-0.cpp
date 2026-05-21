class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix[0][0] > target) return false;

        // search on matrix[0] first
        // then search on matrix[target_row]
        int l = 0, r = matrix.size() - 1;

        while (l <= r) {
            const int mid = (l + r) / 2;
            if (matrix[mid][0] < target) l = mid + 1;
            if (matrix[mid][0] > target) r = mid - 1;
            if (matrix[mid][0] == target) return true;
        }

        if (l == matrix.size()) l--;
        if (matrix[l][0] > target && l != 0) l--;

        // reset
        const int row = l;
        l = 0;
        r = matrix[0].size() - 1;

        while (l <= r) {
            const int mid = (l + r) / 2;
            if (matrix[row][mid] < target) l = mid + 1;
            if (matrix[row][mid] > target) r = mid - 1;
            if (matrix[row][mid] == target) return true;
        }

        return false;
    }
};
