class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;

        auto can_decode = [](char prev, char curr) -> int {
            const int i_prev = (int)(prev - '0');
            const int i_curr = (int)(curr - '0');
            if (i_prev == 0 || i_prev > 2) return 0;
            if ((i_prev * 10 + i_curr) <= 26) return 1;
            return 0;
        };

        auto not_zero = [](char curr) -> int {
            if ((int)(curr - '0') == 0) return 0;
            return 1;
        };

        vector<int> ways(s.size(), 0);
        ways[0] = 1;
        ways[1] = not_zero(s[1]) + can_decode(s[0], s[1]);

        for (int i = 2; i < s.size(); ++i) {
            const char p = s[i - 1];
            const char c = s[i];

            if (!not_zero(c) && !can_decode(p, c)) // is zero && cannot decode
                return 0;

            if (!not_zero(c)) { // is zero, should decode with prev char
                ways[i] = ways[i - 2];
                continue;
            }

            ways[i] = ways[i - 1] + (can_decode(p, c) ? ways[i - 2] : 0);
        }

        return ways[s.size() - 1];
    }
};
