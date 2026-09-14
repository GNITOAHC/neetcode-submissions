class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0)) return -1;

        int ans = -1;

        int start = 0, remain = 0;
        for (int i = 0; i < gas.size(); ++i) {
            remain += (gas[i] - cost[i]);
            if (remain < 0) { // can't start from `start`
                remain = 0;
                start = i + 1;
            }
        }

        if (remain < 0 || start == gas.size()) return -1;
        return start;
    }
};
