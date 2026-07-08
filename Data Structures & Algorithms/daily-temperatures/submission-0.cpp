class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st; // (temp, idx)
        vector<int> v(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            if (st.empty()) {
                st.push({temperatures[i], i});
                continue;
            }

            while (!st.empty()) {
                auto [temp, idx] = st.top();
                if (temperatures[i] > temp) {
                    st.pop();
                    v[idx] = i - idx;
                } else break;
            }
            st.push({temperatures[i], i});
        }

        return v;
    }
};
