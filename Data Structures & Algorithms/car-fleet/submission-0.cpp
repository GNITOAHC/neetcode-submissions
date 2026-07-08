class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // sort by destination
        vector<pair<int, int>> v; // {pos, speed}
        for (int i = 0; i < position.size(); ++i)
            v.push_back({position[i], speed[i]});
        sort(v.rbegin(), v.rend());

        stack<double> st;
        for (auto const [p, s] : v) {
            const double time = (target - p) / (double)s;
            if (st.empty()) {
                st.push(time);
                continue;
            }
            const double prev = st.top();

            // if prev fleet time < cur fleet time, merge
            // keep last position as represent
            if (time <= prev) continue;
            st.push(time);
        }

        return st.size();
    }
};
