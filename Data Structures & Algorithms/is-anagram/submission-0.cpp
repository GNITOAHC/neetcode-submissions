class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        for (const char c : s) count[c - 'a'] += 1;
        for (const char c : t) count[c - 'a'] -= 1;

        for (const int i : count)
            if (i != 0) return false;
        return true;
    }
};
