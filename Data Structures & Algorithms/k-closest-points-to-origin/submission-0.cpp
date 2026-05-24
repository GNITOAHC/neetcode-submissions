class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // min heap
        std::priority_queue<
            std::pair<int, int>, std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>> mh;

        for (int i = 0; i < points.size(); ++i) {
            mh.push({
                std::pow(points[i][0], 2) + std::pow(points[i][1], 2),
                i
            });
        }

        vector<vector<int>> v;
        while (k--) {
            auto [_dis, idx] = mh.top();
            mh.pop();
            v.push_back({points[idx][0], points[idx][1]});
        }

        return v;
    }
};
