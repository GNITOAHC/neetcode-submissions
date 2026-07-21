class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            const int mid =  l + (r - l) / 2; // prevent overflow

            if (nums[0] <= target) { // target in left half
                if (target < nums[mid]) r = mid - 1;
                if (nums[mid] < target && nums[mid] < nums[0]) r = mid - 1; // mid in right half
                if (nums[mid] < target && nums[0] <= nums[mid]) l = mid + 1; // mid in left half
            }
            if (target < nums[0]) { // target in right half
                if (nums[mid] < target) l = mid + 1;
                if (target < nums[mid] && nums[mid] < nums[0]) r = mid - 1; // mid in right half
                if (target < nums[mid] && nums[0] <= nums[mid]) l = mid + 1; // mid in left half
            }

            if (target == nums[mid]) return mid;
        }

        return -1;
    }
};
