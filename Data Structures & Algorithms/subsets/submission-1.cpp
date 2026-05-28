class Solution {
public:
    vector<vector<int>> res = {};
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr = {};
        dfs(nums, curr, 0);

        return res;
    }
private:
    void dfs(vector<int>& nums, vector<int>& curr, int idx) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }

        // either don't include nums[idx]
        dfs(nums, curr, idx + 1);

        // or include nums[idx]
        curr.push_back(nums[idx]);
        dfs(nums, curr, idx + 1);
        
        // should pop back after used for DFS
        // because it's using a reference (reducing space complexity)
        curr.pop_back();
    }
};
