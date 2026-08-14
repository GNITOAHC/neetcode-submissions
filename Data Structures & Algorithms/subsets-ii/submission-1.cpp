class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> cur;
        dfs(nums, cur, 0);
        return vector<vector<int>>(s.begin(), s.end());
    }

private:
    void dfs(vector<int>& nums, vector<int> cur, int idx) {
        // either include or exlude nums[idx]
        if (nums.size() <= idx) {
            s.insert(cur);
            return;
        }
        // exclude
        dfs(nums, cur, idx + 1);
        // include
        cur.push_back(nums[idx]);
        dfs(nums, cur, idx + 1);
        cur.pop_back();

        return;
    }
};
