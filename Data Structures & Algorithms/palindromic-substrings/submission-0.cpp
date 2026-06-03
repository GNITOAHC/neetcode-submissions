class Solution {
public:
    int countSubstrings(string s) {
        if (s.length() == 1) return 1;
        // two pointers
        int count = 0, l = 0, r = 0;
        for (int i = 0; i < s.length(); ++i) {
            l = i, r = i; // odd length palindrome
            while (l >= 0 && r < s.length() && s[l] == s[r]) { // expand check
                --l;
                ++r;
                ++count;
            }
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            l = i, r = i + 1; // even palindrome
            while (l >= 0 && r < s.length() && s[l] == s[r]) { // expand check
                --l;
                ++r;
                ++count;
            }
        }

        return count;
    }
};
