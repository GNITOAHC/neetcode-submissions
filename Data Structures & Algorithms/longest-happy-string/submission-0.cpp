class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<char, int>> v {{'a', a}, {'b', b}, {'c', c}};

        auto v_sort = [&]() -> void {
            std::sort(v.begin(), v.end(),
                [](const pair<char, int> p1, const pair<char, int> p2) {
                    return p1.second > p2.second;
                }
            );
            for (auto it = v.begin(); it != v.end();) {
                if (it->second == 0) it = v.erase(it);
                else ++it;
            }
        };
        auto v_erase = [&](const char c) -> void {
            for (int i = 0; i < v.size(); ++i) {
                auto [cc, n] = v[i];
                if (cc == c) v[i].second -= 1;
            }
            v_sort();
        };

        v_sort();

        string ans = "";
        bool append = false;
        while (!v.empty()) {
            const int len = ans.size() - 1; // idx
            append = false;

            for (int i = 0; i < v.size(); ++i) {
                if (ans.size() < 2) {
                    ans += v[i].first;
                    v_erase(v[i].first);
                    append = true;
                    break;
                }
                const char cur = v[i].first;
                if (ans[len] != cur || ans[len - 1] != cur) {
                    ans += cur;
                    v_erase(cur);
                    append = true;
                    break;
                }
            }
            if (!append) break;
            // cout << ans << endl;
        }

        return ans;
    }
};