class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        std::priority_queue<int, vector<int>, std::greater<int>> pq;

        /*
         * Heap with size k, loop over nums
         * Time: O(nlog(k))
         * Space: O(k)
         */
        for (const int& i : nums) {
            pq.push(i);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
