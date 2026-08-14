class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        vector<int> left(nums.size());
        vector<int> right(nums.size());

        left[0] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            left[i] = left[i - 1] + nums[i - 1];
        }

        right[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; 0 <= i; --i) {
            right[i] = right[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (left[i] == right[i]) return i;
        }

        return -1;
    }
};