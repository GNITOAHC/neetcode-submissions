class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int prev = l;
        while (l < r) {
            if (l == r - 1 && nums[l] > nums[r]) return nums[r];
            else if (nums[l] > nums[r]) {
                prev = l;
                l = (l + r) / 2;
            }
            else if (nums[l] < nums[r]) {
                r = l;
                l = prev;
            }
        }

        return nums[l];
    }
};
