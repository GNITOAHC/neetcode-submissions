class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hashmap solution
        vector<string> strs_copy(strs);
        std::unordered_map<std::string, vector<int>> m;
        for (int i = 0; i < strs_copy.size(); ++i) {
            std::sort(strs_copy[i].begin(), strs_copy[i].end());
            m[strs_copy[i]].push_back(i);
        }

        vector<vector<string>> vvs;
        for (auto const& [k, v] : m) {
            vector<string> vs;
            for (auto const& i : v)
                vs.push_back(strs[i]);
            vvs.push_back(vs);
        }

        return vvs;
    }
};
