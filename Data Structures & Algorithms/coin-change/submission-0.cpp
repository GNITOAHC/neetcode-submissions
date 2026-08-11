class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        queue<pair<int, int>> q; // queue<used count, sum>
        q.push({0, 0});
        
        vector<bool> memo(amount, false);
        memo[0] = true;

        while (!q.empty()) {
            auto [used, sum] = q.front();
            q.pop();

            for (const int& c : coins) {
                if (amount - c < sum) continue; // checking if amount < sum - c, but preventing overflow
                if (amount == sum + c) return used + 1;

                if (memo[sum + c]) continue;
                q.push(pair<int, int>{used + 1, sum + c});
                memo[sum + c] = true;
            }
        }

        return -1;
    }
};
