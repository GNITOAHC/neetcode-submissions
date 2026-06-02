class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;

        vector<int> climb(n + 1, 0);

        climb[1] = 1;
        climb[2] = 2;
        for (int i = 3; i < climb.size(); ++i) {
            climb[i] = climb[i - 1] + climb[i - 2];
        }

        return climb[n];
    }
};
