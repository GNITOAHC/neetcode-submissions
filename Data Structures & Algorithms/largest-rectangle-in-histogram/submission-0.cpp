class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // index, height
        int rect = 0;

        for (int i = 0; i < heights.size(); ++i) {
            const int height = heights[i];

            if (st.empty()) {
                st.push({i, height});
                continue;
            }

            if (st.top().second < height) {
                st.push({i, height});
                continue;
            }
            
            // monotonic stack
            int callbackIdx = i;
            while (!st.empty() && height <= st.top().second) {
                auto [topIdx, topHeight] = st.top();
                st.pop();
                rect = std::max(rect, (i - topIdx) * topHeight);
                callbackIdx = topIdx;
            }
            st.push({callbackIdx, height});
        }

        // calculate remaining elements
        while (!st.empty()) {
            const auto [curIdx, curHeight] = st.top();
            st.pop();
            rect = std::max(rect, ((int)heights.size() - curIdx) * curHeight);
        }

        return rect;
    }
};
