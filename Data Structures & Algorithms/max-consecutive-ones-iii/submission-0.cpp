class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_length = 0;

        // sliding window, window can contain at most k zeros
        int l = 0, used_zeros = 0;
        for (int r = 0; r < nums.size(); ++r) {
            used_zeros += nums[r] == 0;
            while (l < nums.size() && k < used_zeros) {
                used_zeros -= nums[l] == 0;
                ++l;
            }
            max_length = std::max(max_length, r - l + 1);
        }

        return max_length;
    }
};