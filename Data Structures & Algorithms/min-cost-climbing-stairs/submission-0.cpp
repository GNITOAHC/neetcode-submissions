class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // top of the staircase idx is cost.size()
        vector<int> dp(cost.size() + 1, 0);

        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = std::min(
                cost[i - 1] + dp[i - 1],
                cost[i - 2] + dp[i - 2]
            );
        }

        return dp[dp.size() - 1];
    }
};
