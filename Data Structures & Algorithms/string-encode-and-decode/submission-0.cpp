class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (auto const& ss : strs)
            s += std::to_string(ss.size()) + '#' + ss;
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        bool reading_num = true;
        string number_string = "";
        int num = -1, i = -1;

        for (char const& c : s) {
            if (reading_num) {
                if (c == '#') {
                    reading_num = false;
                    num = std::stoi(number_string);
                    strs.push_back("");
                    i++;
                }
                else { number_string += c; }
            } else {
                strs[i] += c;
                --num;
            }
            if (num == 0) {
                number_string = "";
                num = -1;
                reading_num = true;
            }
        }

        return strs;
    }
};
