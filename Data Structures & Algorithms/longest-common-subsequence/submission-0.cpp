class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() > text2.size()) std::swap(text1, text2);

        //  --- text2 ---
        //  |
        // text1
        //  |
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));

        for (int i = 0; i < dp.size(); ++i)
            dp[i][0] = (text2[0] == text1[i]) ? 1 : 0;
        for (int i = 1; i < dp[0].size(); ++i)
            dp[0][i] = ((dp[0][i - 1] == 1) || text1[0] == text2[i]) ? 1 : 0;

        int res = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                dp[i][j] = std::max({
                    dp[i][j], dp[i][j - 1], dp[i - 1][j]
                });
            }
        }

        return dp[text1.size() - 1][text2.size() - 1];
    }
};
