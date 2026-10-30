class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(100);
        for (auto& vec : flights) {
            const int from = vec[0], to = vec[1], cost = vec[2];
            graph[from].push_back({to, cost});
        }

        vector<int> dis(n, INT_MAX);

        typedef tuple<int, int, int> T;
        auto cmp = [](const T a, const T b) -> bool {
            return get<1>(a) < get<1>(b);
        };
        priority_queue<T, vector<T>, decltype(cmp)> q; // node, cost, stop count

        q.push({src, 0, 0});
        dis[src] = 0;

        while (!q.empty()) {
            const auto [node, dist, stop] = q.top(); q.pop();

            // cout << format("node {}, dist {}, stop {}\n", node, dist, stop);

            for (auto [nei, cost] : graph[node]) {
                if (dis[nei] < dist + cost) continue;
                if (stop == k + 1) continue;
                dis[nei] = dist + cost;
                q.push({nei, dist + cost, stop + 1});
            }
        }

        if (dis[dst] == INT_MAX) return -1;
        return dis[dst];
    }
};
