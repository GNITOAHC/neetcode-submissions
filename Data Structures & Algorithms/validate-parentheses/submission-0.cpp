class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        for (const char& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }

            if (st.empty()) return false;

            if (c == ')' && st.top() != '(') return false;
            if (c == ']' && st.top() != '[') return false;
            if (c == '}' && st.top() != '{') return false;

            st.pop();
        }

        if (st.empty())
            return true;
        return false;
    }
};
