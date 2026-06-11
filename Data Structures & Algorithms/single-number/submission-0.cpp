class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // a xor a = 0
        int r = 0;
        for (const auto n : nums) r ^= n;

        return r;
    }
};
