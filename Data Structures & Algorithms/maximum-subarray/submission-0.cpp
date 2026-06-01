class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int cur = 0;

        for (const auto& n : nums) {
            if (cur < 0) cur = n;
            else cur += n;

            sum = std::max(sum, cur);
        }

        return sum;
    }
};
