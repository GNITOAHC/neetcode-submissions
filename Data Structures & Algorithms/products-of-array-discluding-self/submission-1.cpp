class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 1) return {nums[0]};

        vector<int> r(nums.size()); // Space optimization
        int cum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            r[i] = cum;
            cum *= nums[i];
        }

        cum = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i > 0; --i) {
            r[i] *= cum;
            cum *= nums[i];
        }
        r[0] = cum;

        return r;
    }
};
