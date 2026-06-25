class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<vector<int>> v;
        const int START = 0, END = 1;

        for (const int n : nums) {
            const int prev = n - 1, next = n + 1;
            int startIdx = -1, endIdx = -1;
            bool breakFlag = false;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i][START] <= n && n <= v[i][END]) {
                    breakFlag = true;
                    break;
                }
                if (v[i][START] == next) {
                    startIdx = i;
                    v[i][START] = n;
                }
                if (v[i][END] == prev) {
                    endIdx = i;
                    v[i][END] = n;
                }
            }
            if (startIdx == -1 && endIdx == -1 && !breakFlag) v.push_back({n, n});
            if (startIdx != -1 && endIdx != -1) { // merge
                v.push_back({v[endIdx][START], v[startIdx][END]});
                v.erase(v.begin() + max(startIdx, endIdx));
                v.erase(v.begin() + min(startIdx, endIdx));
            }
        }

        int length = 0;
        for (auto _v : v) length = max(length, _v[1] - _v[0] + 1);
        return length;
    }
};
