class Solution {
public:
    bool isPalindrome(string s) {
        string clean;

        for (const char c : s)
            if (('a' <= tolower(c) && tolower(c) <= 'z')
                    || ('0' <= c && c <= '9'))
                clean += tolower(c);

        int l = 0, r = clean.size() - 1;
        while (l < r) {
            if (clean[l] != clean[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
