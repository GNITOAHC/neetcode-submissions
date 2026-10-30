class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> close, open;
        
        int prev = 0;
        for (const char c : customers) {
            if (c == 'N') open.push_back(prev++ + 1);
            else open.push_back(prev);
        }
        open.insert(open.begin(), 0); //  prepend one for calc close at 0
        open.push_back(prev); // append one for calc close at customers.size() hour
        
        prev = 0;
        close.resize(customers.size(), 0);
        for (int i = customers.size() - 1; 0 <= i; --i) {
            if (customers[i] == 'Y') close[i] = prev++ + 1;
            else close[i] = prev;
        }
        close.insert(close.begin(), close[0]); // prepend one for calc close at 0
        close.push_back(0); // append one for calc close at customers.size() hour

        int min_p = INT_MAX;
        int idx_min_p;
        for (int i = 0; i <= customers.size(); ++i) {
            const int penalty = open[i] + close[i + 1];
            if (penalty < min_p) {
                min_p = penalty;
                idx_min_p = i;
            }
        }

        //   Y Y N Y
        // 0 0 0 1 1 1 (cum open penalty)
        // 3 3 2 1 1 0 (cum close penalty) (from back)

        // for (int i = 0; i < open.size(); ++i) {
        //     cout << open[i] << ' ';
        // }
        // cout << endl;
        // for (int i = 0; i < close.size(); ++i) {
        //     cout << close[i] << ' ';
        // }
        // cout << endl;

        return idx_min_p;
    }
};