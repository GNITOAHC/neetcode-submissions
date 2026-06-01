class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        int l = 0, r = nums[0];
        int next_r = r;
        int count = 1;

        while (true) {
            if (r >= nums.size() - 1) return count;

            for (int i = l; i <= r; ++i) {
                next_r = std::max(next_r, i + nums[i]);
            }
            l = r + 1;
            r = next_r;
            ++count;
        }
    }
};
