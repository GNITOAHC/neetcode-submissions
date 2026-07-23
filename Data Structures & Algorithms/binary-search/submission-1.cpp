class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            const int mid = l + (r - l) / 2;
            if (target <= nums[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (l < nums.size() && nums[l] == target) {
            return l;
        }
        return -1;
    }
};
