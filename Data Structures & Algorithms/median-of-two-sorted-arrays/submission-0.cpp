class Solution {
public:
    const double DBL_MAX = std::pow(10, 20);

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make sure nums1 has more elements
        if (nums1.size() < nums2.size()) std::swap(nums1, nums2);
        if (nums1.size() == 0) return 0.0;

        // if only nums1 contains element(s)
        if (nums2.size() == 0) {
            if (nums1.size() == 1) return nums1[0];
            if (nums1.size() % 2) { // odd
                return (double)nums1[std::ceil(nums1.size() / 2)];
            } else { // even
                return (
                        (double)nums1[nums1.size() / 2 - 1] + (double)nums1[nums1.size() / 2]
                    ) / 2;
            }

        }

        const double total = nums1.size() + nums2.size();
        auto condition = [&](const int mid) -> bool {
            const int idx2 = std::ceil(total / 2) - (mid + 1) - 1;
            if (idx2 < 0) return true; // mid already contains sufficient elements
            if (nums2.size() <= idx2) return false;
            if (nums1.size() <= mid) return false;
            if (nums2[idx2] < nums1[mid + 1]) return true;
            return false;
        };

        int l = 0, r = nums1.size() - 1;
        while (l < r) {
            const int mid = l + (r - l) / 2;
            if (condition(mid)) r = mid;
            else l = mid + 1;
        }

        // calculate median
        const int idx2 = std::ceil(total / 2) - (l + 1) - 1;

        if ((int)total % 2 == 0) { // even
            double right1 = DBL_MAX, right2 = DBL_MAX, left1 = -DBL_MAX, left2 = -DBL_MAX;
            if (l + 1 < nums1.size()) right1 = nums1[l + 1];
            if (idx2 + 1 < nums2.size()) right2 = nums2[idx2 + 1];
            left1 = nums1[l];
            if (0 <= idx2 && idx2 < nums2.size()) left2 = nums2[idx2];

            return (std::max(left1, left2) + std::min(right1, right2)) / 2;
        } else return std::max((double)nums1[l], (0 <= idx2 && idx2 < nums2.size() ? (double)nums2[idx2] : -DBL_MAX)); // odd

        return -DBL_MAX;
    }
};
