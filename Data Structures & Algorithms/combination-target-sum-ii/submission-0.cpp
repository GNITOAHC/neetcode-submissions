class Solution {
public:
    vector<vector<int>> comb = {};
    int target = -1;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        this->target = target; // setup class-wise target

        dfs(candidates, {}, 0, 0);

        return this->comb;
    }
private:
    void dfs(vector<int>& candidates, vector<int> curr, int idx, int sum) {
        if (sum > this->target) return;
        if (sum == this->target) {
            this->comb.push_back(curr);
            return;
        }
        if (idx >= candidates.size()) return;

        // do not include candidates[idx]
        // should skip duplicate items
        int skip = 1;
        int curr_item = candidates[idx];
        while (idx + skip < candidates.size()
                && candidates[idx + skip] == curr_item) {
            ++skip;
        }
        dfs(candidates, curr, idx + skip, sum);

        // include candidates[idx]
        curr.push_back(candidates[idx]);
        dfs(candidates, curr, idx + 1, sum + candidates[idx]);

        // clear
        curr.pop_back();
    }
};
