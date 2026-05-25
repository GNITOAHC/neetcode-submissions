class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> s;
        for (const int& n : nums) {
            if (s.count(n)) return true;
            s.insert(n);
        }

        return false;
    }
};