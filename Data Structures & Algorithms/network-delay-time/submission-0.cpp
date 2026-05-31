class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited(n + 1, false); // init n + 1 nodes
        visited[0] = true; // idx 0 is not included

        // distance vector
        vector<int> disv(n + 1, INT_MAX);
        disv[k] = 0;

        // distance graph m[source] = vector of {target, distance}
        unordered_map<int, vector<pair<int, int>>> m;
        for (const auto& time : times) {
            m[time[0]].emplace_back(time[1], time[2]);
        }

        // min heap -> {idx, distance}
        typedef std::pair<int, int> PII;
        auto cmp = [](const PII& a, const PII& b) {
            return a.second > b.second;
        };
        priority_queue<PII, std::vector<PII>, decltype(cmp)> h(cmp);

        h.push({k, 0});

        while(!h.empty()) {
            const auto [curr, curr_dis] = h.top();
            h.pop();

            if (visited[curr]) continue;
            visited[curr] = true;

            for (const auto& [idx, dis_to_target] : m[curr]) {
                if (visited[idx]) continue;
                if (curr_dis + dis_to_target < disv[idx]) {
                    disv[idx] = curr_dis + dis_to_target;
                    h.push({idx, disv[idx]});
                }
            }
        }

        for (const bool v : visited)
            if (!v) return -1;

        int ans = 0;
        for (int i = 1; i < disv.size(); ++i)
            ans = std::max(ans, disv[i]);

        return ans;
    }
};
