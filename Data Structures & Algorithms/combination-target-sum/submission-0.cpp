class Solution {
public:
    vector<vector<int>> res = {};
    int target = 0;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->target = target; // set member variable

        vector<int> curr = {};
        dfs(nums, curr, 0, 0);
        
        return res;
    }
private:
    void dfs(vector<int>& nums, vector<int>& curr, int curr_sum, int idx) {
        if (curr_sum > target) return;
        if (idx >= nums.size()) {
            if (curr_sum == target)
                res.push_back(curr);
            return;
        }

        // either don't include nums[idx]
        dfs(nums, curr, curr_sum, idx + 1);

        // or include nums[idx] and stay at idx
        curr.push_back(nums[idx]);
        dfs(nums, curr, curr_sum + nums[idx], idx);
        curr.pop_back();
    }
};
