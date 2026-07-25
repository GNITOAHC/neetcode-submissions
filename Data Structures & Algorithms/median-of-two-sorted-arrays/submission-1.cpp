class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // search on the smaller array
        if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);

        const int total = nums1.size() + nums2.size();
        const int half = (total + 1) / 2;
        if (total == 0) return 0.0;

        auto condition = [&](const int partition1) -> bool {
            const int partition2 = half - partition1;
            const int right1 = partition1 < nums1.size() ? nums1[partition1] : INT_MAX;
            const int left2 = partition2 <= 0 ? -INT_MAX : nums2[partition2 - 1];

            return left2 <= right1;
        };

        int l = 0, r = nums1.size(); // search space would be partition count of nums1 (not index)
                                     // select x element(s) from nums1
        while (l < r) {
            const int mid = l + (r - l) / 2;
            if (condition(mid)) r = mid;
            else l = mid + 1;
        }

        const int partition1 = l;
        const int partition2 = half - l;

        const int left1 = partition1 == 0 ? -INT_MAX : nums1[partition1 - 1];
        const int right1 = partition1 < nums1.size() ? nums1[partition1] : INT_MAX;
        const int left2 = partition2 <= 0 ? -INT_MAX : nums2[partition2 - 1];
        const int right2 = partition2 < nums2.size() ? nums2[partition2] : INT_MAX;

        if (total % 2 == 0) { // even
            return ((double)std::max(left1, left2) + (double)std::min(right1, right2)) / 2;
        } else return std::max((double)left1, (double)left2); // odd

        return -INT_MAX;
    }
};
