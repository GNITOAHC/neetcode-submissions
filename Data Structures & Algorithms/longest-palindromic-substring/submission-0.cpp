class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) return s.substr(0, 1);
        // two pointers
        int idx_l = 0, max_length = 0;
        int l = 0, r = 1;
        for (int i = 0; i < s.length(); ++i) {
            l = i, r = i; // odd length palindrome
            while (l >= 0 && r < s.length() && s[l] == s[r]) { // expand check
                if (r - l + 1 > max_length) {
                    idx_l = l;
                    max_length = r - l + 1;
                }
                --l;
                ++r;
            }
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            l = i, r = i + 1; // even palindrome
            while (l >= 0 && r < s.length() && s[l] == s[r]) { // expand check
                if (r - l + 1 > max_length) {
                    idx_l = l;
                    max_length = r - l + 1;
                }
                --l;
                ++r;
            }
        }

        return s.substr(idx_l, max_length);
    }
};
