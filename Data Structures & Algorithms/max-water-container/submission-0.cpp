class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int area = INT_MIN;

        while (i < j) {
            const int cur_area =
                std::min(heights[i], heights[j]) * (j - i);
            area = area > cur_area ? area : cur_area;

            // The height is limited by the shorter one,
            // moving the shorter never helped.
            // So to potentially increase the area, we must
            // move the pointer at the shorter line inward
            if (heights[i] < heights[j]) {
                i++;
                continue;
            } else {
                j--;
                continue;
            }
        }

        return area;
    }
};
