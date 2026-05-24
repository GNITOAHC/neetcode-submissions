class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // heapify: O(n)
        std::priority_queue<int> pq(nums.begin(), nums.end()); // O(n) space

        k--;
        while (k--) {
            pq.pop(); // O(logn)
        } // O(klog(n))

        return pq.top();
    }
};
