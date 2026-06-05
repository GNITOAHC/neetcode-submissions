class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx_start = -1, idx_end = -1;

        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] < newInterval[0])
                idx_start = i;
        }
        intervals.insert(intervals.begin() + idx_start + 1, newInterval);

        int curr = idx_start + 1;
        int prev = idx_start;
        // merge front
        while (prev >= 0 && intervals[curr][0] <= intervals[prev][1]) {
            intervals[curr][0] = std::min(intervals[curr][0], intervals[prev][0]);
            intervals[curr][1] = std::max(intervals[curr][1], intervals[prev][1]);
            intervals.erase(intervals.begin() + prev);
            --prev;
            --curr;
        }
        // merge back
        int next = curr + 1;
        while (next < intervals.size() && intervals[next][0] <= intervals[curr][1]) {
            intervals[curr][0] = std::min(intervals[curr][0], intervals[next][0]);
            intervals[curr][1] = std::max(intervals[curr][1], intervals[next][1]);
            intervals.erase(intervals.begin() + next);
        }

        return intervals;
    }
};
