class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int l = 1, r = (x / 2) + 1;
        auto condition = [&](int i) -> bool {
            return x / i < i; // checking x < i^2, but preventing overflow
        };

        while (l < r) {
            const int mid = l + (r - l) / 2;
            if (condition(mid)) r = mid;
            else l = mid + 1;
        }

        // l is the min value satisfying condition(x) inside search space
        return l - 1;
    }
};