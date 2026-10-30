class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // prevent empty string
        s += 'a';
        t += 'a';

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                return same(s.substr(i + 1), t.substr(i)) // del one
                    || same(t[i] + s.substr(i), t.substr(i)) // insert one
                    || same(s.substr(i + 1), t.substr(i + 1)); // replace one
            }
        }

        return false;
    }

    bool same(string s, string t) {
        cout << format("comparing {} and {}\n", s, t);
        return s == t;
    }
};
