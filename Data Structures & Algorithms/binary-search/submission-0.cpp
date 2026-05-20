class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;
            const int n = nums[mid];
            if (n > target) r = mid - 1;
            if (n < target) l = mid + 1;
            if (n == target) return mid;
        }

        if (l > r) return -1;
    }
};
