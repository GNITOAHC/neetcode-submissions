class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i)
            um[nums[i]] = i;

        for (int i = 0; i < nums.size(); ++i) {
            const int diff = target - nums[i];
            if (um.count(diff) && um[diff] != i) // i != j
                return {i, um[diff]};
        }
        return {}; // Assume there is one solution.
    }
};
