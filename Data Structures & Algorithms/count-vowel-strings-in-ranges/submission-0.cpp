class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        auto is_vowel = [](char c) -> bool {
            return c == 'a' || c == 'e' ||
                c == 'i' || c == 'o' || c == 'u';
        };

        // build vec of bool to check if start & end with vowel
        vector<bool> v;
        for (const string& w : words) {
            if (is_vowel(w[0]) && is_vowel(w.back()))
                v.push_back(true);
            else v.push_back(false);
        }

        // for (const auto k : v) {
        //     if (k) cout << "true ";
        //     else cout << "false ";
        // }
        // cout << endl;

        // build prefix sum
        vector<int> p(v.size());
        if (0 < v.size()) p[0] = v[0] == true ? 1 : 0;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i]) p[i] = p[i - 1] + 1;
            else p[i] = p[i - 1];
        }

        // for (const auto k : p) cout << k << ' ';
        // cout << endl;

        vector<int> res;
        for (const auto& q : queries) {
            res.push_back(
                p[q[1]] - p[q[0]] + (v[q[0]] ? 1 : 0)
            );
        }

        return res;
    }
};