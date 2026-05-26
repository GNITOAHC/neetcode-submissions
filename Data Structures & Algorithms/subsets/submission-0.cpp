class Solution {
public:
    vector<vector<int>> res = {};
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        rec({}, nums, 0);

        return res;
    }
private:
    void rec(vector<int> curr, vector<int>& nums, int idx) {
        if (idx == nums.size()) return;

        // either exclude current index
        // if exclude current index, no need to push to response again
        rec(curr, nums, idx + 1);

        // or include current index
        curr.push_back(nums[idx]);
        res.push_back(curr);
        rec(curr, nums, idx + 1);
    }
};
