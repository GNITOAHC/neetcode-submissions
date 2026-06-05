class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](vector<int>& a, vector<int>& b) -> bool {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        };
        std::sort(intervals.begin(), intervals.end(), cmp);

        // merge back (from idx 0)
        int curr = 0;
        while (curr + 1 < intervals.size()) {
            if (intervals[curr + 1][0] <= intervals[curr][1]) {
                intervals[curr][1] = std::max(
                    intervals[curr][1], intervals[curr + 1][1]
                );
                intervals.erase(intervals.begin() + curr + 1);
                continue;
            }
            ++curr;
        }

        return intervals;
    }
};
