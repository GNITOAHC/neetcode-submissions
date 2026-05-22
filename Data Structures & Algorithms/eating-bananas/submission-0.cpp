class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());        
        int l = 1, r = piles[piles.size() - 1];

        int k = INT_MAX;

        auto count_time = [&](int _k) {
            int t = 0;
            for (const int& p : piles)
                t += (p % _k == 0) ? (int)(p / _k) : (int)(p / _k) + 1;

            return t;
        };

        while (l <= r) {
            const int mid = (int)((l + r) / 2);
            const int time = count_time(mid);

            if (time > h) l = mid + 1;
            if (time <= h) {
                k = std::min(k, mid);
                r = mid - 1;
            }
        }

        return k;
    }
};
