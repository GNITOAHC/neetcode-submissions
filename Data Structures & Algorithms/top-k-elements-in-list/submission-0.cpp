class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> mm;
        for (auto const& n : nums) mm[n]++;  // <num, count>

        // for (auto const& [k, v] : mm) cout << k << " " << v << endl;

        std::vector<std::pair<int, int>> vp;
        for (auto const& [k, v] : mm) vp.push_back({k, v});
        std::sort(vp.begin(), vp.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<int> v;
        for (int i = 0; i < vp.size() && k--; i++)
            v.push_back(vp[i].first);

        return v;
    }
};
