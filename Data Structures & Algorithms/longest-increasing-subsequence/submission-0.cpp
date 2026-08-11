class Solution {
public:
    vector<vector<int>> memo;
    int lengthOfLIS(vector<int>& nums) {
        this->memo = vector<vector<int>>(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return dfs(nums, -1, 0); // nums, last considered index, new index
    }
private:
    // dfs returns lis count starting from idx
    // e.g. dfs(nums, -1, 3) returns lis starting from idx 3
    int dfs(vector<int>& nums, int last, int idx) {
        if (nums.size() <= idx) return 0;

        // dynamic programming
        if (last != -1 && memo[last + 1][idx] != -1)
            return memo[last + 1][idx];

        // include this idx (if increasing, else remain zero)
        int include = 0;
        if (last == -1 || nums[last] < nums[idx]) {
            if (last != -1 && memo[last + 1][idx] != -1) include = memo[last + 1][idx];
            else {
                include = 1 + dfs(nums, idx, idx + 1);
            }
        }

        // skip this idx
        int skip = dfs(nums, last, idx + 1);

        memo[last + 1][idx] = std::max(include, skip); // last can be -1, so +1 to prevent SIGSEGV
        return std::max(include, skip);
    }
};
