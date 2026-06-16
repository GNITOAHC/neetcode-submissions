class Solution {
private:
    vector<vector<int>> r = {};
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> remain(nums);
        vector<int> cur;
        dfs(nums, cur, remain);

        return r;
    }

    void dfs(vector<int>& nums, vector<int>& cur, vector<int>& remain) {
        if (remain.size() == 0) {
            r.push_back(cur);
            return;
        }

        for (int i = 0; i < remain.size(); ++i) {
            const int next = remain[i];
            cur.push_back(next);
            remain.erase(remain.begin() + i);
            dfs(nums, cur, remain);
            remain.insert(remain.begin() + i, next);
            cur.pop_back();
        }

        return;
    }
};
