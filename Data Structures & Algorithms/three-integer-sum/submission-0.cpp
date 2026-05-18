class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::set<vector<int>> s;

        for (int i = 0; i < nums.size(); ++i) {
            int target = 0 - nums[i];
            int frnt = 0, back = nums.size() - 1;
            while (frnt < back) {
                if (frnt == i) {
                    ++frnt;
                    continue;
                }
                if (back == i) {
                    --back;
                    continue;
                }
                const int sum = nums[frnt] + nums[back];
                if (sum < target) {
                    frnt++;
                    continue;
                }
                if (sum > target) {
                    back--;
                    continue;
                }
                
                vector<int> v = {nums[i], nums[frnt], nums[back]};
                std::sort(v.begin(), v.end());

                if (sum == target) {
                    s.insert(v);
                    ++frnt;
                    --back;
                    continue;
                }
            }
        }

        vector<vector<int>> vv;
        for (const vector<int> v : s) vv.push_back(v);
        return vv;
    }
};
