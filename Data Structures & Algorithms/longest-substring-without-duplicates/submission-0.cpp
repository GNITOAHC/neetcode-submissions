class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if ((int)s.length() <= 1) return s.length();

        int frnt = 0, back = 0;
        int length = 0;

        // characters[ascii - ' '] = count
        // first printable ascii char is space
        // there are 95 printable ascii characters
        std::vector<int> cs(100, 0);
        cs[s[0] - ' '] = 1;

        while (back < (int)s.length() - 1) {
            ++back;
            const int back_idx = s[back] - ' ';
            cs[back_idx] += 1;

            int frnt_idx = s[frnt] - ' ';
            while(cs[back_idx] != 1 && frnt <= back) {
                cs[frnt_idx]--;
                ++frnt;
                frnt_idx = s[frnt] - ' ';
            }

            length = std::max(length, back - frnt + 1);
        }

        return length;
    }
};
