class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::max(nums[0], nums[1]);

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = std::max(
                dp[i - 1],          // don't rub this house
                dp[i - 2] + nums[i] // rub this house
            );
        }

        return std::max(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};
