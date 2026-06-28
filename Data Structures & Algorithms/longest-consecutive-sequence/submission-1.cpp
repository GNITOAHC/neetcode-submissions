class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int length = 0;
        
        for (const int i : s) {
            const int prev = i - 1;
            if (s.count(prev)) continue;

            int n = 1;
            while (s.count(i + n)) n++;
            length = max(length, n);
        }

        return length;
    }
};
