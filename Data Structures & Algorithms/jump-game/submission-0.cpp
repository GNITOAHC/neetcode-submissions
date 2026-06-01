class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1; // the target we want to jump to
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (target - i <= nums[i]) target = i;
        }

        if (target == 0) return true;
        return false;
    }
};
