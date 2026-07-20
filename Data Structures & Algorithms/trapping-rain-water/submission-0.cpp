class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxL = height[l], maxR = height[r];
        int area = 0;

        int cur = 0;
        while (l < r) {
            if (height[l] < height[r]) cur = height[++l];
            else cur = height[--r];

            area += std::max(0, std::min(maxL, maxR) - cur);

            maxL = std::max(maxL, height[l]);
            maxR = std::max(maxR, height[r]);
        }

        return area;
    }
};
