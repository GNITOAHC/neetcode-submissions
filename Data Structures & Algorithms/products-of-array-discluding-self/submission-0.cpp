class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 1) return {nums[0]};

        vector<int> front(nums.size());
        vector<int> back(nums.size());

        front[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            front[i] = front[i - 1] * nums[i];
        
        back[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; --i)
            back[i] = back[i + 1] * nums[i];

        vector<int> r;
        r.push_back(back[1]); // first element = back[0]
        for (int i = 1; i < nums.size() - 1; ++i)
            r.push_back(front[i - 1] * back[i + 1]);
        r.push_back(front[nums.size() - 2]); // last element = front[-1]

        return r;
    }
};
