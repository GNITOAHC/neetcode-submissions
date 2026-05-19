class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0; // left pointer
        std::map<char, int> m;

        int length = 0;

        int max_freq = 0; // the count number of the most frequency char
        for (int r = 0; r < (int)s.length(); ++r) {
            m[s[r]]++;;
            max_freq = std::max(max_freq, m[s[r]]); // Check if the new char's frequency exceed the old one

            // r - l + 1 is the current sliding window span
            // span number - max_freq is the number that we need to change
            // e.g. the max_freq char is 'c', span number - max_freq equals the total char
            // that we need to change to 'c'
            while (r - l + 1 - max_freq > k) {
                m[s[l]]--;
                l++;
            }

            length = std::max(length, r - l + 1);
        }

        return length;
    }
};
