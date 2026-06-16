class Solution {
private:
    vector<vector<int>> r;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> cur;
        dfs(nums, cur, 0);

        return r;
    }

    void dfs(vector<int>& nums, vector<int>& cur, const int idx) {
        if (idx >= nums.size()) {
            r.push_back(cur);
            return;
        }

        // either exclude nums[idx] and skip all same numbers
        int i = 1;
        while (idx + i < nums.size() && nums[idx + i] == nums[idx])
            ++i;
        dfs(nums, cur, idx + i);

        // or include nums[idx]
        cur.push_back(nums[idx]);
        dfs(nums, cur, idx + 1);
        cur.pop_back();

        return;
    }
};
