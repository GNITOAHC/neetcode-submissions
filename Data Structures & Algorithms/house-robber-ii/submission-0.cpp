class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::max(nums[0], nums[1]);
        if (nums.size() == 3)
            return std::max({nums[0], nums[1], nums[2]});

        vector<int> dp1(nums.size() - 1, 0); // don't rub first house
        std::span<int> view1(nums.data() + 1, nums.size() - 1);
        dp1[0] = view1[0];
        dp1[1] = std::max(view1[0], view1[1]);
        
        vector<int> dp2(nums.size() - 1, 0); // don't rub last house
        std::span<int> view2(nums.data(), nums.size() - 1);
        dp2[0] = view2[0];
        dp2[1] = std::max(view2[0], view2[1]);

        for (int i = 2; i < dp1.size(); ++i) {
            dp1[i] = std::max(dp1[i - 1], dp1[i - 2] + view1[i]);
        }
        for (int i = 2; i < dp2.size(); ++i) {
            dp2[i] = std::max(dp2[i - 1], dp2[i - 2] + view2[i]);
        }

        return std::max({
            dp1[dp1.size() - 1], dp1[dp1.size() - 2],
            dp2[dp2.size() - 1], dp2[dp2.size() - 2],
        });
    }
};
