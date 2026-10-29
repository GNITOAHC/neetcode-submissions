class Solution {
public:
    vector<string> expand(string s) {
        this->ans.clear();

        // {a,b}c{d,e}f -> ab c de f
        vector<string> options;
        bool brace = false;
        string cur = "";
        for (const char c : s) {
            if (c == ',') continue;
            if (c == '{') {
                brace = true;
                cur = "";
                continue;
            }
            if (c == '}') {
                brace = false;
                options.push_back(cur);
                cur = "";
                continue;
            }

            if (brace) {
                cur += c;
            } else {
                options.push_back(std::string{c});
            }
        }

        string tmp = "";
        dfs(options, tmp, 0);

        return this->ans;
    }

private:
    vector<string> ans;

    void dfs(vector<string>& v, string& cur, const int idx) {
        if (idx == v.size()) {
            this->ans.push_back(cur);
            return;
        }

        for (int i = 0; i < v[idx].size(); ++i) {
            cur += v[idx][i];
            dfs(v, cur, idx + 1);
            cur.pop_back();
        }

        return;
    }
};
